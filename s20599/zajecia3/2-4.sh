#!/bin/bash

for i in $(ls *.c);
do
    cc $i -o ${i%.*}
done