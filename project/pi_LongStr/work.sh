#!/bin/bash

for i in `seq 11 19`; do
    scp str.sh pi$i:~/
    ssh pi$i "./str.sh ~/ pi$i > ~/out.log"
    scp pi$i:~/out.log ~/pi_LongStr/pi$i.log
    ssh pi$i "rm str.sh out.log"
done

for i in `seq 11 19`; do
    cat pi${i}.log | sort >> ~/pi_LongStr/pilog
    rm pi${i}.log
done

echo "#Problem 1" > ans
cat pilog | sort -n -r | head -n 3 >> ans
scp ans pi20:~/
rm ans pilog
