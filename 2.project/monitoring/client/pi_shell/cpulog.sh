#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S` # 时间
cpu_1=(`cat /proc/stat | cut -d " " -f 3- | awk '{if(NR==1)print}'`) # cpu信息
sleep 0.5
cpu_2=(`cat /proc/stat | cut -d " " -f 3- | awk '{if(NR==1)print}'`) # 0.5秒后cpu信息
for i in `seq 0 $[${#cpu_1[@]}-1]`; do
    total=$[${total}+${cpu_2[$i]}-${cpu_1[$i]}] # cpu全部差
done
idle=$[${cpu_2[3]}-${cpu_1[3]}] # cpu空闲差
cpu_usage=`echo "scale=2;100 - ($idle * 100 / $total)" | bc` # cpu占用率
cpu_load=(`cat /proc/loadavg | awk '{print $1" "$2" "$3}'`) # cpu负载
cpu_temp=`cat /sys/class/thermal/thermal_zone0/temp | awk '{printf("%.2f",$1/1000)}'` # cpu温度（小数)
temp=`echo "scale=0;$cpu_temp*100/100" | bc` # cpu温度（整数）

if [[ $temp -le 50 ]]; then 
    warning="normal"
elif [[ $temp -le 70 ]]; then
    warning="note"
else
    warning="warning"
fi

echo "$time ${cpu_load[0]} ${cpu_load[1]} ${cpu_load[2]} $cpu_usage ${cpu_temp}℃  $warning"
