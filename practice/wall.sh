#!/bin/bash

# 模拟wall命令

for i in `w -h | awk '{printf $2}'`; do
    echo "`who ma i`" >> /dev/$i
    echo $1 >> /dev/$i
done
