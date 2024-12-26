#include <stdio.h>

#include "../../Include/Loot/LootTable.h"

void LootTable::addItem(std::unique_ptr<LootItem> item) {
    items.push_back(std::move(item));
}
