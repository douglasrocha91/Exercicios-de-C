#ifndef ITEM_H
#define ITEM_H

#include <string>

struct Item {
    std::string id;
    std::string name;
    std::string description;
    bool is_takeable; // Whether the item can be picked up

    Item() = default;
    Item(const std::string& id, const std::string& name, const std::string& description, bool takeable = true);
};

#endif // ITEM_H