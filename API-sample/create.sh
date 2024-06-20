#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Error: Exactly one argument is required." >&2
    exit 1
fi

PROJECT_NAME="$1"

if [[ ! "$PROJECT_NAME" =~ ^[a-zA-Z0-9_-]+$ ]]; then
    echo "Error: Available characters for the argument: [a-z, A-Z, 0-9, -, _]" >&2
    exit 1
fi

if [[ ! "$PROJECT_NAME" =~ ^[a-zA-Z0-9].*[a-zA-Z0-9]$ ]]; then
    echo "Error: Argument must start and end with a letter or number." >&2
    exit 1
fi


mkdir $1
cp -r led1/objs $1
cp led1/Makefile $1
cp led1/led1.c $1/$1.c
cp led1/led1.cdl $1/$1.cdl
cp led1/led1.cfg $1/$1.cfg
cp led1/led1.h $1/$1.h
grep -lr "led1" ./$1/ | xargs sed -i".bak" -e "s/led1/$1/g"
rm -rf $1/*bak
