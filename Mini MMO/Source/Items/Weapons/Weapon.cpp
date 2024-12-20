#include <stdio.h>
#include <string>

#include "../../../Include/Items/Equipment/Weapon.h"
#include "../../../Include/Items/Equipment/WeaponSlot.h"
#include "../../../Include/Items/Equipment/WeaponType.h"

Weapon::Weapon(std::string& name, ItemQuality quality, WeaponSlot slot, WeaponType type) : Item(name, quality), slot(slot), type(type) {}
