#ifndef LootTable_h
#define LootTable_h

#include <vector>
#include <memory>

#include "LootItem.h"

class LootTable {
private:
    std::vector<std::unique_ptr<LootItem>> items;

public:
    void addItem(std::unique_ptr<LootItem> item);

    const std::vector<std::unique_ptr<LootItem>>& getItems() const { return items; }
};

#endif
