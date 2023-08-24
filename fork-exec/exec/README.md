# Parallel Task Scheduler with Execution Time Measurement

This project demonstrates a parallel task scheduler that manages the concurrent execution of multiple tasks and measures their execution times. The main program spawns child processes to run an executable named `app.cpp` with varying sleep durations. The execution time of each child process is measured, and the results are displayed.

## File: `task_scheduler.c`

This C file contains the implementation of the parallel task scheduler. It creates child processes to run the executable `app.cpp` with different sleep durations. The execution times of the tasks are measured and displayed in a formatted output.

## Compilation and Execution

1. **Compiling the Program**

    To compile the program, open a terminal and navigate to the directory containing the source code file (`task_scheduler.c`). Use the following command:

    ```bash
    gcc task_scheduler.c -o task_scheduler
    ```

2. **Running the Program**

    Execute the compiled program using the following command:

    ```bash
    ./task_scheduler
    ```

    The program will continuously spawn child processes to run the `app.cpp` executable with varying sleep durations. It will measure and display the execution times of each task.

## File: `app.cpp`

This C++ file contains the implementation of the executable that is run by the child processes. It takes a command-line argument representing the sleep duration in seconds. The program sleeps for the specified duration and then exits.

## Compilation and Execution

1. **Compiling the Program**

    To compile the program, open a terminal and navigate to the directory containing the source code file (`app.cpp`). Use the following command:

    ```bash
    g++ app.cpp -o app
    ```

2. **Running the Program**

    Execute the compiled program using the following command, providing the desired sleep duration as a command-line argument:

    ```bash
    ./app <sleep_duration>
    ```

    For example, to sleep for 3 seconds:

    ```bash
    ./app 3
    ```

## How It Works

- The main program (`task_scheduler.c`) creates child processes to run the `app.cpp` executable.

- Each child process is assigned a random sleep duration between 1 and 5 seconds.

- The execution time of each child process is measured using the `gettimeofday()` function.

- The formatted output includes the current date, time, execution time, and the original sleep duration.

## Notes

- This project illustrates parallel task scheduling and execution time measurement using forked child processes.

- The `app.cpp` executable simply sleeps for the specified duration. It serves as an example of a task that takes time to complete.

**Important**: Keep in mind that this code may not include robust error handling and security considerations needed for production use.
