# Parallel Task Manager using Forking in C

This project showcases a parallel task manager in C using the fork system call. It efficiently manages multiple child processes to execute tasks concurrently. Each child process executes a task, and upon completion, the parent process relaunches the same task on a new child process. The system supports a maximum of 5 tasks running concurrently.

## File: `parallel_task_manager.c`

This C file contains the implementation of the parallel task manager. It creates child processes to perform tasks concurrently and handles their execution and relaunching.

## Compilation and Execution

1. **Compiling the Program**

    To compile the program, open a terminal and navigate to the directory containing the source code file (`parallel_task_manager.c`). Use the following command:

    ```bash
    gcc parallel_task_manager.c -o parallel_task_manager
    ```

2. **Running the Program**

    Execute the compiled program using the following command:

    ```bash
    ./parallel_task_manager
    ```

    The program will manage and monitor the execution of tasks by creating child processes.

## How It Works

- The program utilizes the `fork()` system call to create child processes. Each child process is responsible for executing a task.

- The parent process keeps track of the child processes' IDs and their completion status.

- Each child process executes a task with a random execution time between 1 and 5 seconds.

- After a task completes, the parent process relaunches the same task on a new child process.

- The program demonstrates the parallel execution of tasks and manages child processes effectively.

## Notes

- The program demonstrates basic parallelism using forked child processes. However, in real-world scenarios, more advanced synchronization mechanisms and error handling would be required.

- This example provides insights into managing parallel tasks in a simple manner. For more complex scenarios, consider using threading libraries or advanced parallel programming techniques.
