#ifndef Weapon_h
#define Weapon_h

#include "../Item.h"
#include "WeaponType.h"
#include "WeaponSlot.h"

class Weapon : Item {
private:
    WeaponSlot slot;
    WeaponType type;
public:
    Weapon(std::string& name, ItemQuality quality, WeaponSlot slot, WeaponType type);
    
    WeaponSlot getSlot() const { return slot; }
    WeaponType getType() const { return type; }
};

#endif 
