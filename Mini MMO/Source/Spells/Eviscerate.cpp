#include <iostream>
#include <random>

#include "../../Include/Entities/Entity.h"
#include "../../Include/Resources/Resource.h"
#include "../../Include/Spells/Eviscerate.h"

Eviscerate::Eviscerate(int level) : Spell("Eviscerate", 30 + level * 10, 50 + level * 5), baseDamage(50 + level * 5), damagePerLevel(5.0f) {}

void Eviscerate::cast(Entity& caster, Entity* target) const {
    // Calculate base damage for this spell
    int finalDamage = baseDamage + (caster.getLevel() * damagePerLevel);

    // Add randomness
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_real_distribution<> distribution(0.9, 1.1);

    float randomMultiplier = distribution(generator);
    finalDamage = static_cast<int>(finalDamage * randomMultiplier);
    finalDamage = static_cast<int>(finalDamage * (caster.getAttackPower() / 100.0f));

    // Apply the damage to the target
    if (target) {
        target->takeDamage(finalDamage);
    } else {
        std::cout << "Cast Eviscerate with " << finalDamage << " damage!" << std::endl;
    }
}
