#include <memory>
#include <random>

#include "../../Include/Entities/Creature.h"
#include "../../Include/InGameClasses/InGameClassType.h"
#include "../../Include/Loot/LootItem.h"
#include "../../Include/Loot/LootTable.h"

Creature::Creature(int id, const std::string& name, int level, InGameClassType type) : Entity(name, level, type) {
    generateLoot();
}

void Creature::generateLoot() {
    std::unique_ptr<LootItem> sword = std::make_unique<LootItem>("Rusty Sword", ItemQuality::Common, 0.25f);
    lootTable.addItem(std::move(sword));
    std::unique_ptr<LootItem> linenCloth = std::make_unique<LootItem>("Rusty Sword", ItemQuality::Common, 1.0f);
    lootTable.addItem(std::move(linenCloth));
}

void Creature::dropLoot() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Loop through the loot table and drop items based on chance
    for (const auto& lootItem : lootTable.getItems()) {
        float randValue = dis(gen);
        if (randValue <= lootItem->getChance()) {
            std::cout << getName() << " has dropped " << lootItem->getName() << "." << std::endl;
            
            // Add logic to place item in inventory, etc.
        }
    }
}

void Creature::die() {
    Entity::die();
    dropLoot();
}
