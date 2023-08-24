# Parallel Minimum Finder Using Pthreads and Semaphores

This C program demonstrates parallel minimum finding using pthreads and semaphores.
It initializes an array `A` of size `SIZE` with random values.
The program then uses multiple threads to find the minimum value in the array.

### How It Works

1. The program initializes an array `A` of size `SIZE` with random values between 0 and 99.
2. Semaphores `sem` are initialized to control thread synchronization.
3. The program enters a loop where it repeatedly reduces the stride value by half.
4. In each iteration of the loop, `stride` threads are created to compare and update elements in the array.
5. Each thread compares elements at index `i` and `i + stride`, updating `A[i]` if necessary.
6. Threads are synchronized using semaphores to avoid race conditions.
7. The loop continues until `stride` becomes 0, indicating that all elements have been compared.
8. Finally, the minimum value is printed from `A[0]`.

### Compilation and Execution

Compile the program:

```
gcc -o parallel_min_finder parallel_min_finder.c -lpthread`
```

Run the program:

```
./parallel_min_finder
```
