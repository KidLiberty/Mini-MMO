#include <stdio.h>

#include "../../Include/Spells/Fireball.h"

Spell::Spell(const std::string& spellName, int cost, int spellDamage) : name(spellName), resourceCost(cost), damage(spellDamage) {}
