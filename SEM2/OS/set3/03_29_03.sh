#!/bin/bash
size=0
for i in *;do
    if [ -f $i ];then
        
        s=`ls -l $i|tr -s " "| cut -d " " -f5`
        size=`expr $s + $size`
        
    fi
done
echo Total Bytes used:$size