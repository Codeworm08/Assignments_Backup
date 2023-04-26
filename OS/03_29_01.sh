#!/bin/bash

filename="1In.txt"


if [ -e "$filename" ]; then 
  while read line; do
    read -ra values <<< "$line"
    sum=0
    for value in "${values[@]}"; do
      sum=`expr $sum + $value`
    done
    echo  "${sum}" 
  done < "$filename"
else
  echo "File not found."
fi

