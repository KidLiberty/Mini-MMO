#ifndef LOOTITEM_H
#define LOOTITEM_H

#include <string>

#include "../Items/Item.h"

class LootItem : public Item {
private:
    float dropChance; // Chance for the item to be dropped
    
public:
    LootItem(const std::string& name, ItemQuality quality, float dropChance);

    float getDropChance() const { return dropChance; }
    void setDropChance(float newChance) { dropChance = newChance; }
};

#endif
