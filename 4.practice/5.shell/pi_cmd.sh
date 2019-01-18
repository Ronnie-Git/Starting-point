#!/bin/bash

for i in `seq 11 20`; do
    if [[ $1 == scp ]]; then
        scp $2 pi$i:~/
    fi
    if [[ $1 == ssh ]]; then
        ssh pi$i $2
    fi
done
