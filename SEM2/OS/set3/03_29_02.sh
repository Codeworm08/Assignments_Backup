#!/bin/bash
fileCount=0
dCount=0
files=()
directories=()
for i in `ls`;do
  if [ -f $i ]; then
    fileCount=`expr $fileCount + 1`
    files+=($i)
  elif [ -d $i ]; then
    dCount=`expr $dCount + 1`
    directories+=($i)
  fi
done
echo "File Count = ${fileCount}"
echo "Directory Count = ${dCount}"
echo "Files:"
for i in "${files[@]}"
do
  echo "$i"
done
echo "Directories:"
for i in "${directories[@]}"
do
  echo "$i"
done
