#!/bin/bash

function kolorowanka {
    echo -e "\e[$2m$1\e[0m"
}
kolorowanka $1 $2