#ifndef Eviscerate_h
#define Eviscerate_h

#include <iostream>

#include "../Resources/Resource.h"
#include "Spell.h"

class Eviscerate : public Spell {
private:
    int baseDamage;
    float damagePerLevel;
public:
    Eviscerate(int level);
    
    void cast(Entity& caster, Entity* target = nullptr) const override;
};

#endif
