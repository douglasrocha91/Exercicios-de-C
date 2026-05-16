#include <iostream>
#include <string>
#include <vector>
#include "world.h"

// Function to split a string by delimiter
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to trim whitespace from a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

// Function to convert string to lowercase
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void printHelp() {
    std::cout << "Available commands:\n";
    std::cout << "  look - Describe current location\n";
    std::cout << "  go <direction> - Move to a connected location\n";
    std::cout << "  inventory - Show items in your inventory\n";
    std::cout << "  take <item> - Take an item from current location\n";
    std::cout << "  drop <item> - Drop an item from inventory to current location\n";
    std::cout << "  save - Save game state to files\n";
    std::cout << "  load - Load game state from files\n";
    std::cout << "  help - Show this help message\n";
    std::cout << "  quit - Exit the game\n";
}

int main() {
    World world;
    std::string input;

    std::cout << "Welcome to the Enhanced Text Adventure!\n";
    std::cout << "Type 'help' for a list of commands.\n\n";

    // Load initial game data
    if (!world.loadLocationsFromFile("locations.txt")) {
        std::cout << "Warning: Could not load locations.txt. Using default locations.\n";
        // Create some default locations if file doesn't exist
        world.addLocation(Location("forest", "You are in a dense forest. The trees are tall and the air is fresh."));
        world.addLocation(Location("cave", "You are in a dark cave. You can hear water dripping."));
        world.addLocation(Location("village", "You are in a small village. There are houses and people around."));
        world.addLocation(Location("lake", "You are at a serene lake. The water is clear and calm."));

        // Set connections (simplified)
        // In a full implementation, we'd properly set up the connections vector
    }

    if (!world.loadItemsFromFile("items.txt")) {
        std::cout << "Warning: Could not load items.txt. Using default items.\n";
        // Create some default items
        world.addItem(Item("sword", "Rusty Sword", "An old but serviceable sword.", true));
        world.addItem(Item("key", "Iron Key", "A heavy iron key that might open doors.", true));
        world.addItem(Item("bread", "Loaf of Bread", "A fresh loaf of bread.", true));
        world.addItem(Item("statue", "Stone Statue", "An ancient stone statue. Too heavy to carry.", false));

        // Place items in locations (simplified)
        // In a full implementation, we'd have location-specific items
    }

    // Set starting location
    if (world.getLocationIds().size() > 0) {
        world.setCurrentLocation(world.getLocationIds()[0]);
    }

    bool running = true;
    while (running) {
        // Display current location
        Location* current = world.getCurrentLocation();
        if (current) {
            std::cout << "\n" << current->description << "\n";
        } else {
            std::cout << "\nYou are in an unknown location.\n";
        }

        // Get user input
        std::cout << "\n> ";
        std::getline(std::cin, input);

        if (input.empty()) continue;

        // Parse command
        std::vector<std::string> parts = split(input, ' ');
        std::string command = toLower(trim(parts[0]));
        std::string argument = (parts.size() > 1) ? trim(parts[1]) : "";

        // Process command
        if (command == "quit") {
            running = false;
            std::cout << "Thank you for playing!\n";
        }
        else if (command == "help") {
            printHelp();
        }
        else if (command == "look") {
            // Already displayed above, but we can show it again
            Location* current = world.getCurrentLocation();
            if (current) {
                std::cout << current->description << "\n";

                // Show items in location (simplified)
                // In a full implementation, we'd check which items are in this location
                std::cout << "You see: [items would be listed here]\n";

                // Show available exits (simplified)
                std::cout << "Obvious exits: [exits would be listed here]\n";
            }
        }
        else if (command == "go") {
            if (argument.empty()) {
                std::cout << "Go where? Please specify a direction.\n";
            } else {
                // In a full implementation, we'd check if the direction is valid
                // For now, we'll just try to move to the location with that ID
                if (world.moveToLocation(argument)) {
                    std::cout << "You travel to the " << argument << ".\n";
                } else {
                    std::cout << "You can't go that way.\n";
                }
            }
        }
        else if (command == "inventory") {
            std::vector<std::string> inv = world.getInventory();
            if (inv.empty()) {
                std::cout << "Your inventory is empty.\n";
            } else {
                std::cout << "You are carrying:\n";
                for (const std::string& itemId : inv) {
                    Item* item = world.getItem(itemId);
                    if (item) {
                        std::cout << "  - " << item->name << ": " << item->description << "\n";
                    }
                }
            }
        }
        else if (command == "take") {
            if (argument.empty()) {
                std::cout << "Take what? Please specify an item.\n";
            } else {
                // Check if item exists
                Item* item = world.getItem(argument);
                if (!item) {
                    std::cout << "I don't see that item here.\n";
                }
                // Check if item is takeable
                else if (!item->is_takeable) {
                    std::cout << "You can't take that.\n";
                }
                // Check if already in inventory
                else if (world.hasItem(argument)) {
                    std::cout << "You already have that.\n";
                }
                else {
                    // In a full implementation, we'd check if the item is actually in the current location
                    if (world.addToInventory(argument)) {
                        std::cout << "You take the " << item->name << ".\n";
                    } else {
                        std::cout << "You can't carry any more.\n";
                    }
                }
            }
        }
        else if (command == "drop") {
            if (argument.empty()) {
                std::cout << "Drop what? Please specify an item.\n";
            } else {
                // Check if item is in inventory
                if (!world.hasItem(argument)) {
                    std::cout << "You don't have that item.\n";
                } else {
                    Item* item = world.getItem(argument);
                    if (item) {
                        if (world.removeFromInventory(argument)) {
                            std::cout << "You drop the " << item->name << ".\n";
                            // In a full implementation, we'd add the item to the current location
                        } else {
                            std::cout << "You can't drop that.\n";
                        }
                    }
                }
            }
        }
        else if (command == "save") {
            if (world.saveLocationsToFile("locations.txt") &&
                world.saveItemsToFile("items.txt")) {
                std::cout << "Game saved successfully.\n";
            } else {
                std::cout << "Error saving game.\n";
            }
        }
        else if (command == "load") {
            if (world.loadLocationsFromFile("locations.txt") &&
                world.loadItemsFromFile("items.txt")) {
                std::cout << "Game loaded successfully.\n";
                // Reset to starting location
                if (world.getLocationIds().size() > 0) {
                    world.setCurrentLocation(world.getLocationIds()[0]);
                }
            } else {
                std::cout << "Error loading game.\n";
            }
        }
        else {
            std::cout << "I don't understand that command. Type 'help' for a list of commands.\n";
        }
    }

    return 0;
}