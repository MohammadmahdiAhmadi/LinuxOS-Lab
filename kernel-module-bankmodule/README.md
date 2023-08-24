# Linux Kernel Module Project - Banking System Simulation

Welcome to the Linux Kernel Module Project - a practical exploration of Linux kernel modules and character devices through a simulated banking system. This project aims to provide hands-on experience with kernel module development and interaction. Please note that this project is designed for educational purposes and serves as an opportunity to learn kernel modules, their functionalities, and their interaction with user-space programs.

## Project Overview

This repository contains a Linux kernel module named `bankmodule` that simulates a basic banking system with multiple accounts. The module allows you to perform transactions, check account balances, and manage accounts. The project also includes accompanying shell scripts and user-level test programs that interact with the module, providing a comprehensive learning experience.

## Kernel Module Features

The `bankmodule` kernel module encompasses several features to simulate a simplified banking system:

- **Account Management**: The module supports 100 accounts, each initialized with an initial balance of 2,000,000 units.
- **Transaction Handling**: Perform various types of transactions between accounts, such as transferring funds, making withdrawals, and deposits.
- **Read Operation**: Retrieve account balance information via the `/dev/banknode` device.
- **Write Operation**: Issue transaction commands to the module through the `/dev/banknode` device.

## Practical Exploration

This project is a practical exploration of kernel module development and interaction. Here's an overview of the components included:

- **Kernel Module Source Code**: The core of the project resides in the `bankmodule.c` file. This file contains the source code for the `bankmodule` kernel module, implementing the banking system simulation.

- **Shell Script**: The `bankmodule.sh` script streamlines the compilation, installation, and cleanup of the kernel module. It uses the provided `Makefile` to compile the module, installs it using `insmod`, creates the `/dev/banknode` device node, and facilitates cleaning up if needed.

- **User-Level Test Programs**: The repository offers two user-level test programs:
  - `test_read.c`: This program reads account balances using the `/dev/banknode` device and displays the information in the terminal.
  - `test_write.c`: This program sends transaction commands to the `/dev/banknode` device, simulating transactions between accounts.

## Usage Instructions

1. To compile the kernel module, navigate to the project directory and execute: 

    ```
    make
    ```

2. Install the compiled kernel module, create the device node, and perform necessary setup tasks: 

    ```
    ./bankmodule.sh
    ```

3. Interact with the banking system simulation:
- Run the `test_read` program to view account balances:

  ```
  ./test_read
  ```

- Modify the transaction command in the `buffer` string within `test_write.c` to simulate different transactions, and then run:

  ```
  gcc -o test_write test_write.c
  ./test_write
  ```

## Project Scope

Please note that this project is designed for educational purposes, focusing on practical understanding of Linux kernel modules and their interaction with user-space programs. As with any kernel module development, exercise caution when working with system resources and ensure thorough testing in safe environments.

## Disclaimer

This project is not intended for use in production environments and is purely educational. Always ensure that you have a clear understanding of the implications of kernel module development and adhere to best practices for kernel module management and safety.
