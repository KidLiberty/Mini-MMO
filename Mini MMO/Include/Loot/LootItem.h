#ifndef LOOTITEM_H
#define LOOTITEM_H

#include <string>

#include "../Items/Item.h"

class LootItem : public Item {
private:
    float chance; // Chance for the item to be dropped
    
public:
    LootItem(const std::string& name, ItemQuality quality, float chance);

    float getChance() const { return chance; }
    void setChance(float newChance) { chance = newChance; }
};

#endif
