# Signal Handling in C: Handling SIGALRM

This project demonstrates the handling of signals in a C program using the `SIGALRM` signal. The program initializes a signal handler for the `SIGALRM` signal and waits for the alarm to be triggered. When the alarm signal is received, the handler function is executed.

## File: `signal_handler.c`

This C file contains the implementation of a program that initializes a signal action, assigns a handler to handle the `SIGALRM` signal, and waits for the signal to be triggered. When the `SIGALRM` signal is received, the handler function prints a message indicating that an alarm signal was received.

## Compilation and Execution

1. **Compiling the Program**

    To compile the program, open a terminal and navigate to the directory containing the source code file (`signal_handler.c`). Use the following command:

    ```bash
    gcc signal_handler.c -o signal_handler
    ```

2. **Running the Program**

    Execute the compiled program using the following command:

    ```bash
    ./signal_handler
    ```

    The program initializes the signal handler, sets an alarm to trigger in 5 seconds, and then enters a loop where it repeatedly prints "I am alive!" every second.

3. **Triggering the Signal**

    After 5 seconds, the alarm signal (`SIGALRM`) will be triggered, and the program's signal handler will execute, printing "I received alarm" to the console.

## How It Works

- The program initializes the `sigaction` structure and assigns the `handler1` function to handle the `SIGALRM` signal.

- The program sets an alarm to trigger in 5 seconds using the `alarm()` function.

- The program enters a loop where it repeatedly prints "I am alive!" every second, indicating that it's still running.

- After 5 seconds, the alarm signal is triggered, and the signal handler function `handler1` is executed. It prints "I received alarm" to the console.
