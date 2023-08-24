#!/bin/bash

make
echo "*** program maked ***"

insmod driver.ko
echo "*** driver installed ***"

# Finding major code
major_code=$(cat /proc/devices | grep driver | sed 's/[^0-9]*//g')

mknod /dev/driver c $major_code 0
echo "*** module node created ***"

# ToDo: Runing test program

make clean
rm /dev/banknode
rmmod bankmodule
echo "*** cleaned ***"

