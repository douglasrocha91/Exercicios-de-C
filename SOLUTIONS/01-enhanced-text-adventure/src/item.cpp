#include "item.h"

Item::Item(const std::string& id, const std::string& name, const std::string& description, bool takeable)
    : id(id), name(name), description(description), is_takeable(takeable) {}