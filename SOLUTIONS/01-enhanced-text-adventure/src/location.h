#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

struct Location {
    std::string id;
    std::string description;
    std::vector<std::string> connections; // IDs of connected locations
    std::vector<std::string> items;      // Items present in this location

    Location() = default;
    Location(const std::string& id, const std::string& description);
};

#endif // LOCATION_H