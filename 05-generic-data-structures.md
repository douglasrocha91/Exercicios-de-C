# Exercise 5: Generic Data Structures Library

## Objective
Implement type-generic data structures using void pointers and function pointers.

## Requirements
1. Implement a generic linked list that can store any data type
2. Implement a generic hash table with collision resolution
3. Implement a generic binary search tree
4. Each data structure should support:
   - Insertion, deletion, search
   - Traversal operations
   - Custom comparison and copy functions via function pointers
5. Create test programs for each data structure with different data types

## Concepts to Practice
- Void pointers and type erasure
- Function pointers and callbacks
- Generic programming techniques
- Data structures and algorithms
- Memory management in generic contexts

## Suggested Approach
1. Design a generic linked list interface:
   - Use void* for data storage
   - Require user-provided compare, copy, and free functions
   - Implement basic operations (push, pop, insert, remove, find)
2. Create a hash table with:
   - User-provided hash function and compare function
   - Collision resolution (chaining or open addressing)
   - Resize/rehash functionality
3. Implement a binary search tree with:
   - User-provided compare function
   - Insert, delete, search operations
   - Various traversal methods (in-order, pre-order, post-order)
4. Write comprehensive test programs for each data structure

## Extension Ideas
- Add iterator support to your data structures
- Implement balanced trees (AVL or Red-Black)
- Add persistence capabilities (save/load to disk)
- Implement concurrent versions of the data structures