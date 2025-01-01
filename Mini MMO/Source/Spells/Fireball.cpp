#include <iostream>
#include <random>

#include "../../Include/Entities/Entity.h"
#include "../../Include/Resources/Resource.h"
#include "../../Include/Spells/Fireball.h"

// Constructor
Fireball::Fireball(int level) : Spell("Fireball", 30 + level * 10, 50 + level * 5), baseDamage(50 + level * 5), damagePerLevel(5.0f) {}

void Fireball::cast(Entity& caster, Entity* target) const {
    // Calculate base damage for this spell
    int finalDamage = baseDamage + (caster.getLevel() * damagePerLevel);

    // Random number generator (static ensures it is initialized only once)
    static std::random_device randomDevice;
    static std::mt19937 generation(randomDevice());
    std::uniform_real_distribution<> distribution(0.9, 1.1);

    // Apply random multiplier
    float randomMultiplier = distribution(generation);
    finalDamage = static_cast<int>(finalDamage * randomMultiplier);

    // Optionally, apply caster stats (like spell power) to influence damage
    finalDamage = static_cast<int>(finalDamage * (caster.getSpellPower() / 100.0f));

    // Apply the damage to the target
    if (target) {
        target->takeDamage(finalDamage);
    } else {
        std::cout << "Cast Fireball with " << finalDamage << " damage!";
    }
}

