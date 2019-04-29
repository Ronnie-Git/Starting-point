#!/bin/bash

sum=0
for i in `ls data`; do
    file_line=`awk 'END{print NR}' data/$i`
    sum=$[${sum}+${file_line}]
done

echo "Number of total lines of code: "$sum > output
