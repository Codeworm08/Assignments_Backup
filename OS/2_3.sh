#!/bin/bash
echo `cat /proc/cpuinfo| grep -E 'vendor_id'| head -1| awk -F ': ' '{print $2}'`
echo `cat /proc/cpuinfo| grep -E 'model name'| head -1| awk -F ': ' '{print $2}'`
echo `cat /proc/cpuinfo| grep -E 'cpu MHz'| head -1| awk -F ': ' '{print $2}'`
echo `cat /proc/cpuinfo| grep -E 'cache size'| head -1| awk -F ': ' '{print $2}'`
