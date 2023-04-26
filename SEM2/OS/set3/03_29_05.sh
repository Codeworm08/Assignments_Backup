#!/bin/bash
cd test1
for i in *.sh;do
    s=`echo $i|cut -d "." -f1`
    mv $i $s.exe
done