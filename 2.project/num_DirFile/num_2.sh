#!/bin/bash

#给当前目录下的文件和目录标号

num=0

str=`ls | sort -n -r | grep [0-9] | head -n 1 | cut -d"." -f1`
if [[ $str > 0 ]]; then
    num=$str
fi

for i in `ls | sort -n -r`; do
    if [[ $i == "a.out" ]]; then
        continue
    fi
    if [[ -f $i || -d $i ]]; then
        str=`echo "$i" | cut -d"." -f1 | grep -v "[a-z][A-Z]" | grep "[0-9]"`
        if [[ $str > 0 ]]; then
            continue
        fi
        num=$[${num}+1]
        mv "$i" "${num}.$i"
    fi
done
