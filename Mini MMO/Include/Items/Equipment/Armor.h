#ifndef Armor_h
#define Armor_h

#include "../Item.h"
#include "ArmorType.h"

class Armor : Item {
private:
    ArmorType type;
public:
    Armor();
    void getArmorType() const { return type; }
}

#endif
