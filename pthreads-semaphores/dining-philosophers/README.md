# Dining Philosophers Problem Solution using Semaphores

This code provides a solution to the classical dining philosophers problem using threads and semaphores. The dining philosophers problem is a synchronization problem that demonstrates the challenges of resource allocation and deadlock avoidance. In this problem, a group of philosophers sit at a round table with bowls of spaghetti and forks (chopsticks) between each pair of adjacent philosophers. The philosophers alternate between thinking and eating, but they require two chopsticks to eat.

## How the Solution Works

The code uses POSIX threads (pthread library) and semaphores to implement a solution to the dining philosophers problem. Each philosopher is represented by a separate thread, and semaphores are used to manage access to the chopsticks (resources) that philosophers need to eat.

**1. Data Structures:**
- `phil[N]`: An array representing the philosopher IDs (0 to N-1).
- `chopsticks[N]`: An array indicating the availability of chopsticks (0 for available, 1 for in use).
- `sem_chopsticks[N]`: An array of semaphores, one for each chopstick.

**2. LEFT and RIGHT Functions:**
- `LEFT(phil_id)`: Computes the index of the left chopstick for a given philosopher.
- `RIGHT(phil_id)`: Computes the index of the right chopstick for a given philosopher.

**3. think Function:**
- Simulates the philosopher thinking for a certain period.

**4. can_eat Function:**
- Checks if both left and right chopsticks are available for a philosopher to eat.

**5. eat Function:**
- Acquires the left and right chopsticks using semaphores, simulating eating, and then releases the chopsticks.

**6. philosopher Thread Function:**
- Loops indefinitely:
  - Calls the `think` function to simulate thinking.
  - Repeatedly checks if the philosopher can eat (both chopsticks available).
  - Calls the `eat` function to simulate eating.

**7. Main Function:**
- Initializes semaphores for all chopsticks.
- Creates philosopher threads, passing their IDs to the `philosopher` function.
- Waits for all philosopher threads to finish using `pthread_join`.

## How to Compile and Run

To compile the code, you can use a C compiler like `gcc`:

```
gcc -o dining_philosophers dining_philosophers.c -lpthread
```

To run the compiled program:

```
./dining_philosophers
```

The program will start the philosopher threads, simulating their thinking and eating activities while avoiding deadlock and contention for resources.
