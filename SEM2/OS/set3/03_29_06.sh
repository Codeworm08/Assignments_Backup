#!/bin/bash
scriptCount=0
for i in *.sh;do
    scriptCount=$((scriptCount+1))
done
echo Total scripts are:$scriptCount