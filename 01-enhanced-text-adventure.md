# Exercise 1: Enhanced Text Adventure with Dynamic Memory

## Objective
Extend the simple_world.cpp to use dynamic memory allocation, file I/O, and modular design.

## Requirements
1. Modify the World class to load locations from a configuration file (JSON or custom format)
2. Implement dynamic addition/removal of locations at runtime
3. Add inventory system with item objects
4. Implement save/load game functionality
5. Add non-player characters (NPCs) with basic AI
6. Use structs, pointers, and dynamic memory allocation (malloc/free)

## Concepts to Practice
- File I/O
- Dynamic memory allocation
- Structs and pointers
- Modular programming
- Basic data structures

## Suggested Approach
1. Start by analyzing the existing simple_world.cpp code
2. Design a location file format (e.g., simple text format or JSON)
3. Create functions to load/save locations from/to file
4. Implement dynamic arrays for locations using malloc/realloc
5. Add inventory system with item structs
6. Implement basic NPC behavior
7. Add save/load game state functionality

## Extension Ideas
- Implement a quest system
- Add combat mechanics
- Create a more sophisticated parser for commands
- Add graphical elements using a simple library