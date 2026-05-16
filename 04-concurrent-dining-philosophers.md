# Exercise 4: Concurrent Dining Philosophers Problem

## Objective
Implement a solution to the classic synchronization problem.

## Requirements
1. Create N philosopher threads that think and eat
2. Implement fork/chopstick sharing using synchronization primitives
3. Avoid deadlock and starvation
4. Experiment with different solutions:
   - Mutex-based solution
   - Semaphore-based solution
   - Resource hierarchy solution
5. Measure and report performance metrics

## Concepts to Practice
- Threads and concurrency
- Synchronization primitives (mutexes, semaphores)
- Race conditions
- Deadlock prevention and detection
- Starvation avoidance

## Suggested Approach
1. Create philosopher threads that alternate between thinking and eating
2. Implement shared chopsticks/forks using mutexes or semaphores
3. Start with a naive implementation that causes deadlock
4. Implement solutions to prevent deadlock:
   - Limit the number of philosophers that can sit simultaneously
   - Have odd/even philosophers pick up forks in different order
   - Use a resource hierarchy (number the forks)
5. Measure and compare performance of different solutions
6. Add visualization or logging to observe behavior

## Extension Ideas
- Implement using condition variables for more sophisticated coordination
- Add timing variations to simulate real-world conditions
- Implement deadlock detection and recovery mechanisms
- Create a graphical visualization of the dining philosophers