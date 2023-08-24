# Shared Memory Communication Using C

This project demonstrates inter-process communication using shared memory in C programming. The project consists of two programs, `sender` and `receiver`, which communicate through shared memory segments defined by a common protocol.

## Files

### `protocol.h`

This header file defines the common protocol used by both `sender` and `receiver`. It includes the shared memory structure format, as well as constants for the shared memory name, array size, and string length.

### `sender.c`

The `sender` program creates a shared memory segment, writes data to it, and then exits. It initializes a shared memory structure defined by the protocol and populates it with random numbers and string values.

### `receiver.c`

The `receiver` program opens the same shared memory segment, reads the data from it, and displays the received information. It interprets the shared memory structure according to the defined protocol.

## Compilation and Execution

1. **Compiling the Programs**

    To compile the programs, open a terminal and navigate to the directory containing the source code files (`sender.c`, `receiver.c`, `protocol.h`, `Makefile`). Use the following command to compile both programs:

    ```bash
    make all
    ```

2. **Running the Programs**

    Execute the `sender` program first to populate the shared memory segment with data:

    ```bash
    ./sender
    ```

    Then, run the `receiver` program to read and display the data from the shared memory segment:

    ```bash
    ./receiver
    ```

    The `receiver` program will display the received string and array values.

## How It Works

- The `sender` program creates a shared memory segment and populates it with data according to the protocol. It then exits.

- The `receiver` program opens the same shared memory segment and reads the data, displaying the string and array values.

- The shared memory segment serves as a communication channel between the two programs, allowing them to exchange data.

## Notes

- This example showcases shared memory communication between two processes. Shared memory can be used for efficient data exchange between processes.

- The example assumes a Linux environment due to the use of `shm_open()`, `mmap()`, and related functions.

**Important**: Handle shared memory with caution, as incorrect implementation can lead to data corruption and unpredictable behavior. Always follow best practices for synchronization and ensure your code is robust and safe.
