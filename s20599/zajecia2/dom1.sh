#!/bin/bash
cat $1 | sed ''s/$USER/$(printf "\e[31m$USER\e[0m")/''
