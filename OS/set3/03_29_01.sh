#!/bin/bash

filename="1In.txt"

# Check if the file exists
if [ -e "$filename" ]; then
  # Loop through each line in the file
  while read line; do
    # Read the space-separated values from the line into an array
    read -ra values <<< "$line"
    sum=0
    # Print each value in the array
    for value in "${values[@]}"; do
      sum=`expr $sum + $value`
    done
    echo  "${sum}" 
  done < "$filename"
else
  echo "File not found."
fi

