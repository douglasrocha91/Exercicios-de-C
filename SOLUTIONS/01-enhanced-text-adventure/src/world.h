#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>
#include <unordered_map>
#include "location.h"
#include "item.h"

class World {
public:
    World();
    ~World();

    // Location management
    bool loadLocationsFromFile(const std::string& filename);
    bool saveLocationsToFile(const std::string& filename) const;
    Location* getLocation(const std::string& id);
    bool addLocation(const Location& location);
    bool removeLocation(const std::string& id);
    std::vector<std::string> getLocationIds() const;

    // Item management
    bool loadItemsFromFile(const std::string& filename);
    bool saveItemsToFile(const std::string& filename) const;
    Item* getItem(const std::string& id);
    bool addItem(const Item& item);
    bool removeItem(const std::string& id);
    std::vector<std::string> getItemIds() const;

    // Game state
    void setCurrentLocation(const std::string& locationId);
    std::string getCurrentLocationId() const;
    Location* getCurrentLocation() const;

    // Inventory
    bool addToInventory(const std::string& itemId);
    bool removeFromInventory(const std::string& itemId);
    bool hasItem(const std::string& itemId) const;
    std::vector<std::string> getInventory() const;

    // Movement
    bool moveToLocation(const std::string& locationId);
    std::vector<std::string> getAvailableMoves() const;

private:
    std::unordered_map<std::string, Location> locations;
    std::unordered_map<std::string, Item> items;
    std::string currentLocationId;
    std::vector<std::string> inventory;
};

#endif // WORLD_H