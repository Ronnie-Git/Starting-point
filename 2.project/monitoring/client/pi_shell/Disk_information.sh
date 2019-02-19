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
