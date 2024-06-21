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
cp -r template/objs $1
cp template/Makefile $1
cp template/template.c $1/$1.c
cp template/template.cdl $1/$1.cdl
cp template/template.cfg $1/$1.cfg
cp template/template.h $1/$1.h
grep -lr "template" ./$1/ | xargs sed -i".bak" -e "s/template/$1/g"
rm -rf $1/*bak
