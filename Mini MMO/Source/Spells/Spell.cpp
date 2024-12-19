#include <stdio.h>

#include "../../Include/Spells/Fireball.h"

Spell::Spell(const std::string& spellName, int cost, int spellDamage) : name(spellName), resourceCost(cost), damage(spellDamage) {}

//void Spell::cast(int spellIndex, std::unique_ptr<Resource>& resource) {
//    if (spellIndex < 0 || spellIndex >= spellBook.size()) {
//        throw std::out_of_range("Invalid spell index");
//    }
//
//    auto& spell = spellBook[spellIndex];
//    if (resource->getCurrentAmount() >= spell->getResourceCost()) {
//        spell->cast(); // Assuming cast() does not need resource parameter here
//        resource->consume(spell->getResourceCost());
//    } else {
//        std::cout << "Not enough resource to cast " << spell->getName() << "!\n";
//    }
//}
