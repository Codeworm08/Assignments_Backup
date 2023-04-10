#!/bin/bash

for file in *; do
    if [ -d "$file" ]; then
        echo "$file is a directory"
    else
        echo "$file is not a directory" 
    fi
done
