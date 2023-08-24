# Multi-threaded Vector Dot Product Calculation

This C code calculates the dot product of two random binary vectors using multiple threads. It utilizes the `pthread` library for thread management and semaphores for synchronization. The dot product is the sum of the element-wise products of two vectors.

### How It Works

1. Define the size of vectors (`SIZE`) and the number of threads (`THREADS`).
2. Populate `vect_A` and `vect_B` arrays with random binary values.
3. Print the contents of both vectors.
4. Initialize semaphore `sem1` with an initial value of 1 for critical sections.
5. Create an array of `pthread_t` objects, `threads`, to store thread identifiers.
6. Spawn threads using a loop. Each calculates a partial dot product by iterating over assigned indices in vectors.
7. Threads accumulate products in their `myProduct` variable.
8. Synchronize threads using a semaphore before updating the global `product` variable.
9. Join threads back to the main thread.
10. Print the final dot product result.

### Compilation and Execution

- Compile: 

```
gcc -o vector_dot_product vector_dot_product.c -pthread
```

- Execute: 

```
./vector_dot_product
```
