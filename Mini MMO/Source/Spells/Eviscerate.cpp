#include <iostream>
#include <random>

#include "../../Include/Entities/Entity.h"
#include "../../Include/Resources/Resource.h"
#include "../../Include/Spells/Eviscerate.h"

Eviscerate::Eviscerate(int level) : Spell("Eviscerate", 30 + level * 10, 50 + level * 5), baseDamage(50 + level * 5), damagePerLevel(50.0f) {}

void Eviscerate::cast(Entity& caster, Entity* target) const {
    // Calculate base damage for this spell
    int finalDamage = baseDamage + (caster.getLevel() * damagePerLevel);

    // Add randomness
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.9, 1.1); // 90% to 110%

    float randomMultiplier = dis(gen);
    finalDamage = static_cast<int>(finalDamage * randomMultiplier);

    // Optionally, apply caster stats (like spell power) to influence damage
    finalDamage = static_cast<int>(finalDamage * (caster.getSpellPower() / 100.0f));

    // Apply the damage to the target
    if (target) {
        target->takeDamage(finalDamage);
        std::cout << "Cast Fireball on " << target->getName() << " for " << finalDamage << " damage!\n";
    } else {
        std::cout << "Cast Fireball with " << finalDamage << " damage!\n";
    }
}
