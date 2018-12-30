#!/bin/bash

# 测试哪个IP被占用

for i in `seq $1 $2`; do # seq 产生数
    ping -c 1 -w 1 192.168.2.$i 2>&1 >/dev/null # 将错误输出标准输出 重定向 到ubuntu自带垃圾桶（不在终端上显示）
    if [[ $? -eq 0  ]]; then
        echo "192.168.2.$i"
    fi
done 
