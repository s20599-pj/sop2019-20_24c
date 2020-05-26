#!/bin/bash
regex="\.sh"
if [[ $0 =~ $regex ]]
then
    echo "Skrypt o rozszerzeniu .sh"
else
    mv $0 $0.sh
fi
