#!/bin/bash

function fibonaczi() {
    if (( $1 <= 2 ));
    then
        echo 1
    else
        echo $(( $(fibonaczi $(($1-2))) + $(fibonaczi $(($1-1))) ))
    fi
}
echo "$1 liczba w ciagu fibbonacciego to $(fibonaczi $1)"