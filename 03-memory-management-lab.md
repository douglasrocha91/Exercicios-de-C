# Exercise 3: Memory Management Laboratory

## Objective
Explore various memory allocation patterns and common pitfalls.

## Requirements
1. Implement a custom memory allocator with different allocation strategies (first-fit, best-fit)
2. Create programs that demonstrate:
   - Memory leaks and how to detect them
   - Buffer overflows and prevention techniques
   - Use-after-free errors
   - Double free errors
3. Implement a simple garbage collector for a specific data structure
4. Use tools like valgrind (conceptually) to verify correctness

## Concepts to Practice
- Pointers and dynamic memory allocation
- Memory safety and debugging techniques
- Custom allocators
- Memory leak detection
- Buffer overflow prevention

## Suggested Approach
1. Study how malloc/free work internally
2. Implement a simple memory pool allocator
3. Create test programs that intentionally introduce memory bugs
4. Implement detection mechanisms for each type of bug
5. Compare performance of different allocation strategies
6. Implement a reference counting or mark-sweep garbage collector for a linked list or tree

## Extension Ideas
- Implement memory profiling tools
- Create a memory leak detector that tracks allocation sites
- Implement bounded buffer protection with canaries
- Add support for memory alignment requirements