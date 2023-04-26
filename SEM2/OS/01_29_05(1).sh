#!/bin/bash
#file="01_29_05In.txt"
while read line;do
	user=$line
	name=`cat /etc/passwd|grep $user | cut -d ":" -f1`
	if [ -z "$name" ] ;then
		echo "User $user does not exist!"
	else
		for i in {1..7}
		do
			a[$i]=`cat /etc/passwd|grep $name | cut -d ":" -f$i`
		done

		for i in {1..7}
		do
			echo ${a[$i]}
		done
		break
	fi
done<<"01_29_05In.txt"




