#!/bin/bash
if [[ -e $PWD/config.cfg ]]
then
    ./config.cfg
elif [[ $1 != "" ]]
then
    ./$1
else
    echo "Brak pliku config.cfg oraz argumentu do programu"
fi