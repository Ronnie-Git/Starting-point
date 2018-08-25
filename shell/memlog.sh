#!/bin/bash

time=`date +%Y-%m-%d__%H:%M:%S` # 当前时间
total=(`free -m | awk '{printf $2" "}'`) # 总量
free=(`free -m | awk '{print $4" "}'`) # 剩余量
current_occupancy=$[$[${total[1]}-${free[1]}]*100/${total[1]}] # 当前占用
dynamic=$(echo "scale=1;0.3*$1+0.7*$current_occupancy" | bc) # 占用百分比动态平均值

echo $time ${total[1]}M ${free[1]}M $current_occupancy% $dynamic%
