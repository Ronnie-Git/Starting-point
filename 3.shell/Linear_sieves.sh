#!/bin/bash

for (( i = 0; i <= 10400; i++ )); do
    prime[$i]=0 # 定义数组并初始化为0
done

for (( i = 2; i <= 10000; i++ )); do
    if [[ prime[i] -eq 0 ]]; then
        (( ++prime[0] ))
        prime[${prime[0]}]=$i # ${数组}
    fi
    for (( j = 1; j <= prime[0] && i * prime[j] <= 10000; j++)); do
        prime[$i*${prime[$j]}]=1
        if [[ i%prime[j] -eq 0 ]]; then 
            break
        fi
    done
done

echo "素数个数："${prime[0]}

# 当给数组赋值时 数组不用加$ 下标需要加$
