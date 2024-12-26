#include <stdio.h>
#include <string>

#include "../../Include/Items/Item.h"
#include "../../Include/Items/ItemQuality.h"

Item::Item(const std::string& name, ItemQuality quality) : name(name), quality(quality) {}
