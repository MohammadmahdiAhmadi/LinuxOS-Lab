# Parallel Array Update using Signal and Shared Memory

This project demonstrates parallel array updating using signals and shared memory in a C program. The program spawns multiple child processes, each responsible for updating a portion of a shared array using signals for synchronization.

## File: `parallel_array_update.c`

This C file contains the implementation of a program that creates multiple child processes to update different portions of a shared array using signals for synchronization. The program initializes a signal handler to respond to the `SIGUSR1` signal, and each child process waits for the signal to update its designated array elements.

## Compilation and Execution

1. **Compiling the Program**

    To compile the program, open a terminal and navigate to the directory containing the source code file (`parallel_array_update.c`). Use the following command:

    ```bash
    gcc parallel_array_update.c -o parallel_array_update -lrt
    ```

2. **Running the Program**

    Execute the compiled program using the following command:

    ```bash
    ./parallel_array_update
    ```

    The program initializes the signal handler, creates child processes, and sets up shared memory for array storage. Each child process updates its designated array elements when the `SIGUSR1` signal is received.

3. **Output**

    The program prints the updated array indices and values after all child processes have completed their tasks.

## How It Works

- The program initializes a signal handler to respond to the `SIGUSR1` signal. When a child process receives this signal, it updates its designated array elements.

- The program creates multiple child processes, and each child process is responsible for updating a specific range of array elements.

- Shared memory is used to store the array. Child processes access the shared memory to update the array elements.

## Notes

- The provided code is for educational purposes and may require additional error handling and optimization for production use.

**Important**: Handle signals and shared memory with caution, as incorrect implementation can lead to unpredictable behavior. Always follow best practices for synchronization and ensure your code is robust and safe.
