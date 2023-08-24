# Practical Linux OS Projects in C

Welcome to the collection of practical projects focusing on the Linux Operating System and written in the C programming language. Each project aims to showcase different aspects of Linux system programming, providing hands-on experience and understanding of various concepts.

## Table of Contents

- [**kernel-module-bankmodule**](./kernel-module-bankmodule)
  - Simulates a basic banking system using a Linux kernel module.

- [**kernel-module-ioctl**](./kernel-module-ioctl)
  - Illustrates communication between user space and kernel space using IOCTL commands.

- [**pthreads-semaphores**](./pthreads-semaphores)
  - [dining-philosophers](./pthreads-semaphores/dining-philosophers)
    - Solves the dining philosophers problem using threads and semaphores.
  - [parallel-minimum-finder](./pthreads-semaphores/parallel-minimum-finder)
    - Finds the minimum value in an array using pthreads and semaphores.
  - [dot-product](./pthreads-semaphores/dot-product)
    - Calculates the dot product of binary vectors using pthreads and semaphores.

- [**fork-exec**](./fork-exec)
  - [exec](./fork-exec/exec)
    - Demonstrates a parallel task scheduler managing execution times of tasks.
  - [fork](./fork-exec/fork)
    - Presents a parallel task manager using the fork system call.

- [**pipe-signal**](./pipe-signal)
  - [named-pipe](./pipe-signal/named-pipe)
    - Implements a simple server-client communication system using named pipes. 
  - [ordinary-pipe](./pipe-signal/ordinary-pipe)
    - Demonstrates multi-process communication using pipes and forked child processes.

- [**shared-memory-signal**](./shared-memory-signal)
  - [signal](./shared-memory-signal/signal)
    - Demonstrates signal handling in C using the SIGALRM signal.
  - [shared-memory](./shared-memory-signal/shared-memory)
    - Illustrates inter-process communication using shared memory segments.
  - [shared-memory-signal](./shared-memory-signal/shared-memory-signal)
    - Demonstrates parallel array updating using signals and shared memory.

- [**system-call**](./system-call)
  - No description available
