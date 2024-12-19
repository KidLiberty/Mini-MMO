#include <memory>
#include <vector>

#include "Spell.h"
#include "Fireball.h"

class SpellFactory {
public:
    static std::vector<std::unique_ptr<Spell>> createSpells(InGameClassType classType) {
        std::vector<std::unique_ptr<Spell>> spells;

        switch (classType) {
            case InGameClassType::Mage:
                spells.push_back(std::make_unique<Fireball>());
                // Add more Mage spells here
                break;
            case InGameClassType::Rogue:
                // Add Rogue-specific spells here
                break;
            case InGameClassType::Warrior:
                // Add Warrior-specific spells here
                break;
            default:
                throw std::invalid_argument("Invalid class type");
        }

        return spells;
    }
};
