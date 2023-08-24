# Kernel Module - IOCTL

This repository contains a practical Linux kernel module named `driver` along with associated files for testing and usage. The `driver` module provides IOCTL commands for communication between user space and kernel space.

## Kernel Module
The `driver` module defines a character device and provides the following IOCTL commands:
- `Command1`: Reads an integer argument from user space, performs an operation, and prints the result to the kernel log.
- `Command2`: Performs an internal operation, updates an integer argument, and returns the updated value to user space.

## Building and Installation
To build and install the `driver` module, follow these steps:
1. Navigate to the root directory of the repository.
2. Run the command `make` to build the module.
3. Load the module using `insmod driver.ko`.
4. Identify the major code using `cat /proc/devices`.
5. Create the module node using `mknod /dev/driver c $major_code 0`.

## Usage
To interact with the `driver` module, follow these steps:
1. Compile the `user.c` program using a C compiler (e.g., `gcc -o user user.c`).
2. Run the compiled `user` program to test the IOCTL commands.

## Cleaning Up
To clean up after using the `driver` module, execute the following steps:
1. Remove the module node using `rm /dev/driver`.
2. Unload the module using `rmmod driver`.
3. Run the command `make clean` to remove build artifacts.
