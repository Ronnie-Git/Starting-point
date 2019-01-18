#!/bin/bash

#给当前目录下的文件和目录标号

dirnum=0
filenum=0

for i in `ls`; do
    if [[ $i == "a.out" ]]; then
        continue
    fi
    if [[ -d $i ]]; then
        dirnum=$[${dirnum}+1]
        num=`echo "$i" | cut -d"." -f1`
        if [[ $dirnum == $num ]]; then
            continue
        fi
        mv "$i" "${dirnum}.$i"
    fi
    if [[ -f $i ]]; then
        filenum=$[${filenum}+1]
        num=`echo "$i" | cut -d"." -f1`
        if [[ $filenum == $num ]]; then
            continue
        fi
        mv "$i" "${filenum}.$i"
    fi
done
