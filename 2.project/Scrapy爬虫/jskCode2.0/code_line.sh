#!/bin/bash

OLDIFS=${IFS}
IFS=$'\n'

sum=0
for i in `ls data`; do
    if [[ ! -d data/$i ]]; then
        continue
    fi
    for j in `ls data/$i`; do
        for l in `ls data/$i/"$j"`; do
            file_line=`awk 'END{print NR}' data/$i/"$j"/$l`
            sum=$[${sum}+${file_line}]
        done
    done
done

IFS=${OLDIFS}

echo "Number of total lines of code: "$sum > ./data/code_line_sum
