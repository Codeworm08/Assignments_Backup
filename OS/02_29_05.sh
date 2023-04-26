#!/bin/bash
if [ $# -lt 1 ]
then
	echo "requires path as argument"
	exit 
fi
if [ ! -d $1 ]
then
	echo "Path Invalid!"
	exit
fi
# echo "Disk usage of" $1 " in bytes: $(du -s "$1" | awk '{print $1}') bytes"
# echo "Disk usage of" $1 " in KB: $(du -k "$1" | awk '{print $1}') KB"
# echo "Disk usage of" $1 " in MB: $(du -m "$1" | awk '{print $1}') MB"
# cd $1
# for x in *;do
# 	if  [ -d $x ];then
# 		echo $x
# 		echo "Disk usage of" $x " in bytes: $(du -s "$x" | awk '{print $1}') bytes"
# 		echo "Disk usage of" $x " in KB: $(du -hk "$x" | awk '{print $1}') KB"
# 		echo "Disk usage of" $x " in MB: $(du -hm "$x" | awk '{print $1}') MB"
# 	fi
# done
# i=`du -b $1|tr -s " "`
# echo $i
# f=0
# for x in $i;do
# 	if [ $((f%2)) -eq 0 ];then
# 		echo -n $x Bytes: 
# 	else
# 		echo $x
# 	fi
# 	f=$((f+1))
# done
echo "Usage in bytes: "
du -b $1
echo "Usage in KB: "
du -bk $1
echo "Usage in MB: "
du -bm $1