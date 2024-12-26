#include <stdio.h>

#include "../../Include/Loot/LootItem.h"

LootItem::LootItem(const std::string& name, ItemQuality quality, float chance) : Item(name, quality), chance(chance) {}
