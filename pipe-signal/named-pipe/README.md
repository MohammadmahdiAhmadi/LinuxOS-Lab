# Server-Client Communication Using Named Pipes (FIFOs)

This project demonstrates a simple server-client communication system using named pipes (FIFOs) in C programming language. The server performs basic mathematical operations based on the commands sent by the client and returns the results.

## Files

1. `server.c`: This file contains the server-side code that listens for incoming requests from clients, performs calculations based on the provided command, and sends back the result.

2. `client.c`: This file contains the client-side code that prompts the user to input two numbers and a command (operation) character. It then sends this information to the server and displays the calculated result received from the server.

3. `myh.h`: This header file defines a structure `PipeS` that holds the information sent between the server and the client. It also defines the path for the named pipe.

## Compilation and Execution

1. **Compiling the Server and Client Programs**

    To compile the server and client programs, open a terminal and navigate to the directory containing the source code files (`server.c`, `client.c`, and `myh.h`). Use the following commands:

    ```bash
    gcc server.c -o server
    gcc client.c -o client
    ```

2. **Running the Server**

    Run the compiled server executable by executing the following command:

    ```bash
    ./server
    ```

    The server will start listening for incoming requests.

3. **Running the Client**

    In a separate terminal window, run the compiled client executable:

    ```bash
    ./client
    ```

    The client will prompt you to enter two numbers and a command character. For example, to multiply 37 and 41, you can input `37 41 m`. To calculate the power of 37 raised to the power of 41, input `37 41 p`. The client will display the calculated result received from the server.

4. **Termination**

    To stop the programs, press `Ctrl + C` in the terminal windows running the server and the client.

## Notes

- The communication between the server and client is achieved using named pipes (FIFOs). A named pipe is created using `mkfifo()` and is used as a conduit for data between the processes.

- The `PipeS` structure defined in `myh.h` specifies the format of data exchanged between the server and client.

- The server reads the command, performs the appropriate mathematical operation based on the provided command, and sends the result back to the client.

- This project provides a simple illustration of interprocess communication using named pipes.
