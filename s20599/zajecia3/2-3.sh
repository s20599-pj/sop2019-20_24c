#!/bin/bash
#IFS="  "
lista=$(ls)
for i in $(ls);
do
    echo "Patrzcie Panstwo, oto plik: $i"
done