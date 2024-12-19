#ifndef Fireball_h
#define Fireball_h

#include <iostream>

#include "../Resources/Resource.h"
#include "Spell.h"

class Fireball : public Spell {
private:
    int baseDamage;
    float damagePerLevel; // How much damage increases per level
public:
    Fireball(int level);

    void cast(Entity& caster, Entity* target = nullptr) const override;
};

#endif
