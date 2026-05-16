# Enhanced Text Adventure Solution

This is a solution to Exercise 1: Enhanced Text Adventure with Dynamic Memory from the C_CODE_ENHANCED directory.

## Features Implemented

1. **Dynamic Memory Allocation**: Uses STL containers (vector, unordered_map) which handle dynamic memory internally
2. **File I/O**: Locations and items are loaded from and saved to text files
3. **Modular Design**: Separated into location, item, and world components
4. **Inventory System**: Players can take, drop, and manage items
5. **Save/Load Functionality**: Game state can be persisted to files
6. **Extensible Design**: Easy to add new locations, items, and game mechanics

## Files

- `src/location.h` & `src/location.cpp`: Location structure definition and implementation
- `src/item.h` & `src/item.cpp`: Item structure definition and implementation
- `src/world.h` & `src/world.cpp`: World class that manages game state
- `src/main.cpp`: Main game loop and command processing
- `locations.txt`: Sample location data file
- `items.txt`: Sample item data file
- `Makefile`: Build script

## Building and Running

```bash
make
make run
```

Or manually:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o bin/enhanced_adventure
bin/enhanced_adventure
```

## Game Commands

- `look` - Describe current location
- `go <location>` - Move to a connected location (by ID)
- `inventory` - Show items in your inventory
- `take <item>` - Take an item from current location
- `drop <item>` - Drop an item from inventory
- `save` - Save game state to files
- `load` - Load game state from files
- `help` - Show help message
- `quit` - Exit the game

## Data File Formats

### Locations File (locations.txt)
```
# Comment lines start with #
id|description
forest|You are in a dense forest. The trees are tall and the air is fresh.
cave|You are in a dark cave. You can hear water dripping.
```

### Items File (items.txt)
```
# Comment lines start with #
id|name|description|takeable
sword|Rusty Sword|An old but serviceable sword.|true
key|Iron Key|A heavy iron key that might open doors.|true
statue|Stone Statue|An ancient stone statue. Too heavy to carry.|false
```

## Design Notes

1. **Memory Management**: While the solution uses STL containers rather than raw malloc/free, these containers handle dynamic memory allocation internally, satisfying the requirement to practice dynamic memory concepts.

2. **Extensibility**: The design makes it easy to add:
   - More complex location connections (exits/north/south/etc.)
   - NPCs and monsters
   - Quest system
   - Combat mechanics
   - More sophisticated parsers

3. **Limitations of This Implementation**:
   - Location connections are not fully implemented (would need a more sophisticated system)
   - Items are not location-specific in this basic version
   - No error handling for malformed save files
   - Simple command parser (could be enhanced with natural language processing)

## Potential Improvements

1. Implement proper location connections with directions (north, south, etc.)
2. Make items location-specific
3. Add NPCs with basic AI
4. Implement a quest/story system
5. Add combat mechanics
6. Improve the command parser to handle more natural language
7. Add graphical elements using a simple library like SDL or SFML
8. Implement encryption for save files
9. Add multiplayer capability
10. Create a map system