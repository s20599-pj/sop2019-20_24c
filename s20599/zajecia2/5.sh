#!/bin/bash
A=$1
DLUGOSC=${#A}
if [ ${A:DLUGOSC-1:1} = "a" ]
then
    echo "$A ma kota, a kot ma ${A:0:DLUGOSC-1}e"
else
    echo "$A ma kota, a kot ma ${A}a"
fi