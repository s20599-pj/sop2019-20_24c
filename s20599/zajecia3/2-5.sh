#!/bin/bash

for i in $@;
do
    echo "Plik: $i"
    zawartosc=$(cat $i)
    echo $zawartosc
    dlugosc=${#zawartosc}
    for ((j=$dlugosc; j>0; j--));
    do
        echo -n "${zawartosc:j-1:1}"
    done
done