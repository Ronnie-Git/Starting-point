#!/bin/bash

OLDIFS=${IFS}
IFS=$'\n'

num=0
str=0
way=0
nl=0
op=(0 0 0 0)

filter() {
    a=(rmvb png img jpg jpeg gif md avi zip tar gz 7z sh xmind)
    suffix=`echo $1 | awk -F. '{print $NF}'`
    echo ${a[*]} | grep "$suffix" >/dev/null 2>&1
    if [[ $? -eq 0 ]]; then
        return 1
    fi
    return 0
}

find(){
    IFS=$'\n'
    for i in `ls -A`; do
        file $i | grep "exec" >/dev/null 2>&1
        if [[ $? -eq 0 ]]; then
            continue
        fi
        filter $i
        if [[ $? -eq 1 ]]; then
            continue
        fi
        if [[ $i == ".ssh" || $i == ".bashrc" || $i == ".viminfo" || $i == ".bash_history " ]]; then
            continue
        fi
        if [[ -d $i ]]; then
            cd $i
            find
            cd ..
            continue
        fi
        if [[ ! -f $i ]]; then
            continue
        fi
        IFS=${OLDIFS}
        for j in `cat "$i"`; do
            #n="`echo "$j" | grep " "`"
			#if [[ ${#n} -gt 1 ]]; then
            #    continue
            #fi
			if [[ ${#j} -gt $num ]]; then
                if [[ $l -gt 0 ]]; then
                    if [[ ${#j} -ge ${op[$[$l-1]]} ]]; then
                        continue
                    fi
                fi
                num=${#j}
                op[$l]=$num
                str=$j
                way=`pwd`/"$i"
                nl=`cat "$i" | grep -n "$j" "$i" 2>/dev/null | tail -n 1 | cut -d':' -f1`
            fi
        done
    IFS=$'\n'
    done
}

now=$1
pi=$2
for l in `seq 0 2`; do
    cd $now
    find $l
    cd ..
    echo -e "$num:$str\t$pi:$way\tLine:$nl"
    num=0
done

IFS=${OLDIFS}
