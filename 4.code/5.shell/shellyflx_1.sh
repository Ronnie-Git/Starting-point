#!/bin/bash
num=0
sum=0
for (( i = 2; i <= 10001; i++ )); do
    a=0
    for (( j = 2; j * j <= i; j++ )); do # (()) 括号里可按c语言的格式写
        if [[ i%j -eq 0 ]]; then
            a=1
            break
        fi
    done
    if [[ a -eq 0 ]]; then
        ((num++))
        ((sum+=i)) # 素数求和 (()) 括号里可按c语言的格式写
        echo $i
    fi
done
echo "素数个数: "$num
echo "素数总和："$sum
#注意空格和括号的使用 格式遵照上面样例
