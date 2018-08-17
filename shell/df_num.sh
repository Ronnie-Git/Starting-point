#!/bin/bash

file=0
dir=0

find() {
    for i in `ls -a`; do
        if [[ $i == '.' || $i == '..' ]]; then
            continue
        fi
        if [[ ! -e $i || ! -r $i ]]; then
           continue
        fi
        if [[ -d $i ]]; then
            ((dir++))
            cd $i
            find
            cd ..
            continue
        fi
        if [[ -f $i ]]; then
            ((file++))
        fi
    done
    return
}

cd $1
find

echo "文件个数："$file
echo "目录个数："$dir
