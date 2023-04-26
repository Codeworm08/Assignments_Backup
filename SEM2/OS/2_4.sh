#!/bin/bash
echo $HOME
echo `uname`
echo Version:`lsb_release -d| awk -F ' ' '{print $2}'`
echo "Release Number:"`lsb_release -d| awk -F ' ' '{print $3}'`
echo `cat /proc/sys/kernel/osrelease`
echo `pwd`
