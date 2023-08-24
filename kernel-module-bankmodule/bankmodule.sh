#!/bin/bash

make
echo "*** program maked ***"

insmod bankmodule.ko
echo "*** bankmodule installed ***"

# Finding major code
major_code=$(cat /proc/devices | grep bankmodule | sed 's/[^0-9]*//g')

mknod /dev/banknode c $major_code 0
echo "*** module node created ***"

# ToDo: Runing test program

make clean
rm /dev/banknode
rmmod bankmodule
echo "*** cleaned ***"
