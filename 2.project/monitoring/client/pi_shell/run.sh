#!/bin/bash

for i in `seq 11 20`; do
    ssh pi$i gcc $1 -pthread
done
