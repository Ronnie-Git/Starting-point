#!/bin/bash

for i in `seq 11 20`; do
    scp $1 pi$i:~/
done
