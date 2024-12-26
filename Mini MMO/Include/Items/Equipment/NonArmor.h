#ifndef NonArmor_h
#define NonArmor_h

#include "../Item.h"
#include "NonArmorType.h"

class NonArmor : Item {
private:
    NonArmorType type;
public:
    NonArmor();
    void getNonArmorType() const { return type; }
}

#endif
