# Multi-Process Communication Example

This code demonstrates a multi-process communication scenario in C, using pipes and forked child processes. The program creates a specified number of child processes, each performing a task with a random sleep duration. The parent process then reads the results from the child processes through pipes and calculates the total time spent by the children sleeping.

## Features

- Uses pipes for inter-process communication.
- Utilizes forked child processes to perform tasks concurrently.
- Demonstrates signal handling to terminate child processes when the task is complete.

## Compilation

Compile the code using a C compiler, such as GCC, by executing the following command:

```
gcc -o 1 1.c
```

## Usage

Run the compiled executable:

```
./1
```

1. The program will create child processes and have them perform tasks with random sleep durations.

2. The parent process will calculate the total sleep time by reading results from child processes.

3. The parent process will then terminate all child processes and display the total sleep time.

## Code Explanation

- The program defines the maximum number of child processes (`MAXCHILD`) and the maximum limit of sleep time (`MAXIMUM`).

- The child processes' logic is implemented in the task function, where each child generates a random sleep time between 1 and 5 seconds, sleeps for that duration, and then writes the sleep time to the pipe.

- In the `main` function:
    - An array of pipe file descriptors (`fd[MAXCHILD][2]`) is created to facilitate communication between parent and child processes.
    - The parent process forks child processes, each of which enters the `task` function to perform their tasks.

- After creating child processes, the parent process reads sleep times from child processes through pipes and calculates the total sleep time. The parent process will continue reading until the total sleep time reaches or exceeds the maximum limit.

- Once the task is complete, the parent process sends a kill signal to all child processes using `kill(0, SIGKILL)` and exits.

## Note

- This code is a simplified example of multi-process communication using pipes and may not be suitable for production use. It's designed for educational purposes to demonstrate the basic concepts of inter-process communication and concurrent execution in C.
