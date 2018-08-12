#!/bin/bash
while [[ true ]]; do # 一直循环
    flag=0
    read x # 输入x
    for (( i = 2; i * i <= x; i++ )); do
        if [[ x%i -eq 0 ]]; then
            flag=1
            break
        fi
    done
    if [[ flag -eq 0 ]]; then
        echo "it is a prime"
    else 
        echo "it is not a prime"
    fi
done
