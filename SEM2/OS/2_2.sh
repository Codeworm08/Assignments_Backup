#!/bin/bash
path=$PATH
IFS=':'
for file in $path; do
   echo `ls -l $file` 
done
