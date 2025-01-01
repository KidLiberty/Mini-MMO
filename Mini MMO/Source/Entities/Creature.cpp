#include <memory>
#include <random>
#include <fstream>
#include <iostream>

#include "../../Include/Entities/Creature.h"
#include "../../Include/InGameClasses/InGameClassType.h"
#include "../../Include/Loot/LootItem.h"
#include "../../Include/Loot/LootTable.h"

Creature::Creature(int id, const std::string& name, int level, InGameClassType type) : Entity(name, level, type) {
    generateLoot(id);
}

void Creature::generateLoot(const int id) {
    // Open the JSON file
    std::ifstream file("/Users/brandonstone/C++/Mini MMO/Mini MMO/Data/LootTables/loot_tables.json");
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open loot_tables.json");
    }

    // Parse the JSON
    nlohmann::json jsonData;
    try {
        file >> jsonData;
    } catch (const nlohmann::json::parse_error& e) {
        throw std::runtime_error(std::string("JSON Parsing Error: ") + e.what());
    }

    // Retrieve loot for the specific creature
    bool creatureFound = false;
    for (const auto& creature : jsonData["creature"]) {
        if (creature["id"] == id) {
            creatureFound = true;

            const auto& lootList = creature["loot"];
            for (const auto& item : lootList) {
                std::string name = item["name"];
                std::string quality = item["quality"];
                float dropRate = item["dropRate"];

                // Convert quality to ItemQuality enum
                ItemQuality itemQuality;
                if (quality == "Common") itemQuality = ItemQuality::Common;
                else if (quality == "Uncommon") itemQuality = ItemQuality::Uncommon;
                else if (quality == "Rare") itemQuality = ItemQuality::Rare;
                else if (quality == "Epic") itemQuality = ItemQuality::Epic;
                else throw std::runtime_error("Invalid item quality: " + quality);

                // Add the item to the loot table
                std::unique_ptr<LootItem> lootItem = std::make_unique<LootItem>(name, itemQuality, dropRate);
                lootTable.addItem(std::move(lootItem));
            }
            break; // Stop once the creature is found and loot is processed
        }
    }

    if (!creatureFound) {
        std::cout << "No loot defined for creature ID: " << id << std::endl;
    }
}

void Creature::dropLoot() {
    static std::random_device randomDevice;
    static std::mt19937 generation(randomDevice());
    std::uniform_real_distribution<> distribution(0.0f, 1.0f);

    // Loop through the loot table and drop items based on chance
    for (const auto& lootItem : lootTable.getItems()) {
        float randValue = distribution(generation);
        // Log out various drop chances
        // std::cout << lootItem->getName() << " drop chance: " << randValue << std::endl;
        if (randValue <= lootItem->getDropChance()) {
            std::cout << getName() << " has dropped " << lootItem->getName() << "." << std::endl;
            
            // Add logic to place item in inventory, etc.
        }
    }
}

void Creature::die() {
    Entity::die();
    dropLoot();
}
