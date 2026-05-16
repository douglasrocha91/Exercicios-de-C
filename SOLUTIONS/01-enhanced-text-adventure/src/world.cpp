#include "world.h"
#include <fstream>
#include <sstream>
#include <algorithm>

World::World() : currentLocationId("") {}

World::~World() {
    // Cleanup if needed
}

bool World::loadLocationsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    locations.clear();
    std::string line;
    while (std::getline(file, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string id, description;
        std::getline(iss, id, '|');
        std::getline(iss, description);

        if (!id.empty() && !description.empty()) {
            Location loc(id, description);
            locations[id] = loc;
        }
    }

    file.close();
    return !locations.empty();
}

bool World::saveLocationsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (const auto& pair : locations) {
        const Location& loc = pair.second;
        file << loc.id << "|" << loc.description << "\n";
    }

    file.close();
    return true;
}

Location* World::getLocation(const std::string& id) {
    auto it = locations.find(id);
    if (it != locations.end()) {
        return &it->second;
    }
    return nullptr;
}

bool World::addLocation(const Location& location) {
    if (locations.find(location.id) != locations.end()) {
        return false; // Location already exists
    }
    locations[location.id] = location;
    return true;
}

bool World::removeLocation(const std::string& id) {
    auto it = locations.find(id);
    if (it == locations.end()) {
        return false; // Location not found
    }
    locations.erase(it);
    return true;
}

std::vector<std::string> World::getLocationIds() const {
    std::vector<std::string> ids;
    for (const auto& pair : locations) {
        ids.push_back(pair.first);
    }
    return ids;
}

bool World::loadItemsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    items.clear();
    std::string line;
    while (std::getline(file, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string id, name, description, takeableStr;
        std::getline(iss, id, '|');
        std::getline(iss, name, '|');
        std::getline(iss, description, '|');
        std::getline(iss, takeableStr);

        if (!id.empty() && !name.empty() && !description.empty()) {
            bool takeable = (takeableStr == "true");
            Item item(id, name, description, takeable);
            items[id] = item;
        }
    }

    file.close();
    return !items.empty();
}

bool World::saveItemsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (const auto& pair : items) {
        const Item& item = pair.second;
        file << item.id << "|" << item.name << "|" << item.description << "|"
             << (item.is_takeable ? "true" : "false") << "\n";
    }

    file.close();
    return true;
}

Item* World::getItem(const std::string& id) {
    auto it = items.find(id);
    if (it != items.end()) {
        return &it->second;
    }
    return nullptr;
}

bool World::addItem(const Item& item) {
    if (items.find(item.id) != items.end()) {
        return false; // Item already exists
    }
    items[item.id] = item;
    return true;
}

bool World::removeItem(const std::string& id) {
    auto it = items.find(id);
    if (it == items.end()) {
        return false; // Item not found
    }
    items.erase(it);
    return true;
}

std::vector<std::string> World::getItemIds() const {
    std::vector<std::string> ids;
    for (const auto& pair : items) {
        ids.push_back(pair.first);
    }
    return ids;
}

void World::setCurrentLocation(const std::string& locationId) {
    if (locations.find(locationId) != locations.end()) {
        currentLocationId = locationId;
    }
}

std::string World::getCurrentLocationId() const {
    return currentLocationId;
}

Location* World::getCurrentLocation() const {
    if (currentLocationId.empty()) {
        return nullptr;
    }
    return getLocation(currentLocationId);
}

bool World::addToInventory(const std::string& itemId) {
    // Check if item exists
    if (items.find(itemId) == items.end()) {
        return false;
    }

    // Check if already in inventory
    if (std::find(inventory.begin(), inventory.end(), itemId) != inventory.end()) {
        return false;
    }

    inventory.push_back(itemId);
    return true;
}

bool World::removeFromInventory(const std::string& itemId) {
    auto it = std::find(inventory.begin(), inventory.end(), itemId);
    if (it == inventory.end()) {
        return false; // Item not in inventory
    }
    inventory.erase(it);
    return true;
}

bool World::hasItem(const std::string& itemId) const {
    return std::find(inventory.begin(), inventory.end(), itemId) != inventory.end();
}

std::vector<std::string> World::getInventory() const {
    return inventory;
}

bool World::moveToLocation(const std::string& locationId) {
    Location* loc = getLocation(locationId);
    if (!loc) {
        return false; // Location doesn't exist
    }

    // In a more complex implementation, we'd check if the location is actually connected
    // For now, we'll allow movement to any known location
    setCurrentLocation(locationId);
    return true;
}

std::vector<std::string> World::getAvailableMoves() const {
    Location* current = getCurrentLocation();
    if (!current) {
        return {};
    }
    return current->connections;
}