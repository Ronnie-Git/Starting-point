#!/bin/bash

source ~/project/.backup.rc
TIME_NOW=`date +"%Y-%m-%d %H:%M"`
TIME_FILE=`date +"%Y_%m_%d_%H_%M"`

# dest_dir=~/backup
# back_dir=$1
# log=~/backup/log/backup.log

if [[ ! -d $dest_dir ]]; then
    echo "$TIME_NOW [ERROR] The Dest dir $dest_dir not exists" >> $log
    exit
fi

echo "$TIME_NOW backup started!" >> $log

for i in `echo $back_dir | tr ":" "\n"`; do
    if [[ ! -d $i ]]; then
        echo "%TIME_NOW backup [ERROR] The dir $i not exists" >> $log
    fi
    echo "$i started"
    target=`echo $i | cut -d "/" -f 2- | tr "/" "_"`
    target=${target}_${TIME_FILE}.tar.gz
    tar czPf "${dest_dir}/${target}" $i
    if [[ $? -eq 0 ]]; then
        for i in `du -h ${dest_dir}/${target}`; do
            size=$i
            break
        done
        echo -e "\033[47;34m $TIME_NOW backup $i --> $target +${size} \033[0m" >> $log
    else
        echo "$TIME_NOW [ERROR] Something ..." >> $log
    fi
done

Del_list=`find $dest_dir -name "*.tar.gz" -mmin +3`

for i in $Del_list; do
    for j in `du -h $i`; do
        size=$j
        break
    done
    echo -e "\033[47;34m $TIME_NOW delete $i --> remove -${size} \033[0m" >> $log
    rm -f $i
done
