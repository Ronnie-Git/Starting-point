#!/bin/bash

#给当前目录下的文件和目录标号

dirnum=0
filenum=0
op=0

for i in `ls | sort -n -r | grep [0-9]`; do
    if [[ $op -eq 2 ]]; then
        break;
    fi
    num=`echo "$i" | cut -d"." -f1`
    if [[ -d $i ]]; then
        #if [[ $dirnum -gt 0 ]]; then
        #    continue
        #fi
        if [[ $num > 0 && $dirnum -eq 0 ]]; then
            dirnum=$num
            op=$[$op+1]
            continue
        fi
    fi
    if [[ -f $i ]]; then
        #if [[ $filenum -gt 0 ]]; then
        #    continue
        #fi
        if [[ $num > 0 && $filenum -eq 0 ]]; then
            filenum=$num
            op=$[$op+1]
        fi
    fi
done

for i in `ls | sort -n -r`; do
    if [[ $i == "a.out" ]]; then
        continue
    fi
    if [[ -d $i ]]; then
        str=`echo "$i" | cut -d"." -f1 | grep -v "[a-z][A-Z]" | grep "[0-9]"`
        if [[ $str > 0 ]]; then
            continue
        fi
        dirnum=$[${dirnum}+1]
        mv "$i" "${dirnum}.$i"
        continue
    fi
    if [[ -f $i ]]; then
        str=`echo "$i" | cut -d"." -f1 | grep -v "[a-z][A-Z]" | grep "[0-9]"`
        if [[ $str > 0 ]]; then
            continue
        fi
        filenum=$[${filenum}+1]
        mv "$i" "${filenum}.$i"
    fi
done
