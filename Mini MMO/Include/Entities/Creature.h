#ifndef Creature_h
#define Creature_h

#include <string>
#include <vector>
#include <memory>

#include "Entity.h"
#include "../External/json.hpp"
#include "../Loot/LootTable.h"

class Creature : public Entity {
private:
    float aggressionRadius;
    std::string behavior;
    bool isHostile;

    LootTable lootTable;
public:
    Creature(int id, const std::string& name, int level, InGameClassType type);
    
    // Method to generate loot for the creature
    void generateLoot(const int id);
    void die() override;
    void dropLoot();
    
    float getAggressionRadius() const { return aggressionRadius; }
    void setAggressionRadius(float radius) { aggressionRadius = radius; }
    
    const std::string& getBehavior() const { return behavior; }
    void setBehavior(const std::string& behaviorType) { behavior = behaviorType; }

    bool getIsHostile() const { return isHostile; }
    void setIsHostile(bool hostile) { isHostile = hostile; }

    const LootTable& getLootTable() const { return lootTable; }
};

#endif
