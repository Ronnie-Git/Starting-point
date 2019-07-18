### 1. MEM

在树莓派上，使用Shell编程，输出以下内存信息：

| 时间                 | 总量  | 剩余量 | 当前占用（%） | 占用百分比动态平均值 |
| -------------------- | ----- | ------ | ------------- | -------------------- |
| 2018-01-12__15:00:28 | 1023M | 200M   | 80.4%         | 60.8%                |

**动态平均值=0.3动态平均值（上一次）+0.7当前占用比**

**在脚本编写过程中，可以参考以下内容：**

`awk '{printf("%s %s",$1,$2)}'`

`echo "scale=1;0.3*24+0.7*36" | bc`

`arry=(a c d e f)`

`arry=($1 $2)`

`free -m`  查看内存占用



```bash
#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S` # 当前时间
total=(`free -m | head -n 2 | tail -n 1 | awk '{printf $2" "$4}'`) # 总量 剩余量
current_occupancy=$[$[${total[0]}-${total[1]}]*100/${total[0]}] # 当前占用
dynamic=$(echo "scale=1;0.3*$1+0.7*$current_occupancy" | bc) # 占用百分比动态平均值

echo $time ${total[0]}M ${total[1]}M $current_occupancy% $dynamic%
```





### 2.DISK

1. 磁盘总量
2. 磁盘剩余量
3. 占用比例
   1. 各分区占用比例
   2. 各分区总量
   3. 分区剩余情况

**输出格式：2018-01-12__16:48:23 标识（0为整个磁盘，1为分区） 磁盘还是分区（disk| /boot , /） 磁盘/分区总量 磁盘/分区剩余量 占用比例**

`df` 查看磁盘分区信息

`awk '{printf("a["NR"]=%d",$1)}'` 输出第一行第一个



```bash
#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S` # 时间
information=(`df -T -x devtmpfs -m -x tmpfs | tail -n +2 | awk '{printf("a["NR"]=%s,%d,%d,%s ",$7,$3,$5,$6)}'`) # 磁盘分区信息
Total_memory=0 # 磁盘内存总量
Available_memory=0 # 磁盘可用内存
Occupancy_ratio=0 # 占用比例
((num=${#information[@]}-1)) # 分区总数

# 计算磁盘内存总量 磁盘可用内存 占用比例
for i in `seq 0 $num`; do
    ((Total_memory=$Total_memory+`echo ${information[$i]} | cut -d "," -f 2`))
    ((Available_memory=$Available_memory+`echo ${information[$i]} | cut -d "," -f 3`))
done
((Occupancy_ratio=($Total_memory-$Available_memory)*100/$Total_memory))


# 输出磁盘和分区信息
echo "$time 0 disk $Total_memory $Available_memory $Occupancy_ratio%"
for i in `seq 0 $num`; do
    echo "$time 1 `echo ${information[i]} | cut -d "=" -f 2 | tr "," " "`"
done
```



### 3.系统运行概况

`uname -a` 查看系统全部信息

```bash
#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S` # 时间
system_information=(`uname -a | awk '{print $2" "$15" "$3}'`) # 系统信息
up=`uptime -p | tr -d "," | tr " " "_"` # 运行时间
load_average=`uptime | awk '{printf $8$9$10}'` # 平均负载
information=(`df -m -x tmpfs | tail -n +2 | awk '{printf("%d,%d ",$2,$3 )}'`) # 磁盘分区信息
total=(`free -m | grep Mem | awk '{printf $2" "$3}'`) # 内存总量 剩余量
current_occupancy=$[${total[1]}*100/${total[0]}] # 当前内存占用比例
cpu_temperature=$[`cat /sys/class/thermal/thermal_zone0/temp`/1000] # cpu温度
Alarm=(0 80 90 70 80 50 90) # 警报等级范围 （磁盘占比的两个界限 内存占比的两个界限 cup温度的两个界限）
Percentage=($Occupancy_ratio $current_occupancy $cpu_temperature) # 磁盘占用比例 内存占用比例 cup温度

for i in `seq 0 $[${#information[@]}-1]`; do # $[${#information[@]}-1] 计算总分区数-1
    ((Total_memory=$Total_memory+`echo ${information[$i]} | cut -d "," -f 1`)) # 计算磁盘总量
    ((Occupied_memory=$Occupied_memory+`echo ${information[$i]} | cut -d "," -f 2`)) # 计算已用磁盘量
done
((Occupancy_ratio=$Occupied_memory*100/$Total_memory)) # 计算磁盘占用比例

# 输出系统运行情况
echo -e "$time ${system_information[0]} ${system_information[1]} ${system_information[2]} $up $load_average ${Total_memory}M $Occupancy_ratio% ${total[0]}M $current_occupancy% $cpu_temperature""\c"

for i in {0..2}; do # $i是Percentage数组的下标
    ((Alarm[0]=${Alarm[0]}+1)) # 通过Alarm[0]自加 遍历警报等级范围
    if [[ ${Percentage[$i]} -le ${Alarm[${Alarm[0]}]} ]]; then
        echo -e " normal""\c"
        ((Alarm[0]=${Alarm[0]}+1))
    elif ((Alarm[0]=${Alarm[0]}+1)) && [ ${Percentage[$i]} -le ${Alarm[${Alarm[0]}]} ]; then
        echo -e " note""\c"
    else
        echo -e " waring""\c"
    fi
done
echo
```

