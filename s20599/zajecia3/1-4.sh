#!/bin/bash
linie=$(ls -l | wc -l)

if [[ linie -gt 6  ]] 
then
    echo "Jest wiecej niz 5 plikow"
else
    echo "Jest 5 lub mniej plikow"
fi

