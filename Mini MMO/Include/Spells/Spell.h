#ifndef Spell_h
#define Spell_h

#include <string>

#include "../Resources/Resource.h"

class Spell {
protected:
    std::string name;
    int resourceCost; // or resourceCost, if applicable to Energy/Rage
    int damage;   // Can be 0 for non-damage spells
public:
    Spell(const std::string& spellName, int cost, int spellDamage);

    virtual ~Spell() = default;

    const std::string& getName() const { return name; }
    int getResourceCost() const { return resourceCost; }
    int getDamage() const { return damage; }
};

#endif
