#include <stdio.h>

#include "../../Include/InGameClasses/InGameClassType.h"
#include "../../Include/Spells/SpellFactory.h"
#include "../../Include/Spells/Fireball.h"
#include "../../Include/Spells/Eviscerate.h"

std::vector<std::unique_ptr<Spell>> SpellFactory::createSpells(InGameClassType classType) {
    std::vector<std::unique_ptr<Spell>> spells;

    switch (classType) {
        case InGameClassType::Mage:
            spells.push_back(std::make_unique<Fireball>(1));
            // Add more Mage spells here
            break;
        case InGameClassType::Rogue:
            spells.push_back(std::make_unique<Eviscerate>(1));
            break;
        case InGameClassType::Warrior:
            // Add Warrior-specific spells here
            break;
        default:
            throw std::invalid_argument("Invalid class type");
    }

    return spells;
}
