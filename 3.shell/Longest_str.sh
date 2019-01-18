#!/bin/bash

num=0
file=0
str=0

find() {
    for i in `ls`; do
        if [[ ! -e $i ]]; then # 判断是否存在 不存在执行下一次循环
           continue
        fi
        if [[ -d $i ]]; then # 如果是目录进行递归  
            cd $i
            find
            cd ..
            continue
        fi
        if [[ -f $i ]]; then # 如果是文件进行比较
            for j in `cat $i`; do
                if [[ ${#j} -gt $num ]]; then
                    num=${#j}
                    str=$j
                    file=`pwd`/$i
                fi
            done
        fi
    done
    return
}

cd $1
find

echo "字符串最长的文件路径："$file
echo "最长字符串的长度："$num
echo "最长的字符串："$str
