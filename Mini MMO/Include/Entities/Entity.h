//
//  Entity.h
//  Mini MMO
//
//  Created by Brandon Stone on 12/18/24.
//

#ifndef Entity_h
#define Entity_h

#include <string>
#include <vector>
#include "../InGameClasses/InGameClass.h"

class Entity {
private:
    // TODO: Implement logic for inGameClass to be added to Entity constructor
    // InGameClass inGameClass;
protected:
    std::string name;
    int level;
    int health;
    float movementSpeed;
    
    // Core Stats
    int strength;
    int agility;
    int stamina;
    int intellect;
    int spirit;
    
    // Combat Stats
    int attackPower;
    int spellPower;
    int armor;
    int resilience;
    int defense;
    int dodge;
    int parry;
    int block;
    int haste;
    int crit;
    int hit;
    int expertise;
    int spellCrit;
    
    // Derived Stats
    int damagePerSecond;
    int healingPerSecond;
    int armorPenetration;
    
public:
//    Entity(InGameClass* newClass) : inGameClass(newClass) {
//        inGameClass->ApplyClassMechanics(*this);
//    }
    // Getters and Setters
    const std::string& GetName() const { return name; }
    void SetName(const std::string& newName) { name = newName; }

    int GetLevel() const { return level; }
    void SetLevel(int newLevel) { level = newLevel; }

    int GetHealth() const { return health; }
    void SetHealth(int newHealth) { health = newHealth; }

    int GetAttackPower() const { return attackPower; }
    void SetAttackPower(int newAttackPower) { attackPower = newAttackPower; }

    float GetMovementSpeed() const { return movementSpeed; }
    void SetMovementSpeed(float newSpeed) { movementSpeed = newSpeed; }

    int GetStrength() const { return strength; }
    void SetStrength(int newStrength) { strength = newStrength; }

    int GetAgility() const { return agility; }
    void SetAgility(int newAgility) { agility = newAgility; }

    int GetStamina() const { return stamina; }
    void SetStamina(int newStamina) { stamina = newStamina; }

    int GetIntellect() const { return intellect; }
    void SetIntellect(int newIntellect) { intellect = newIntellect; }

    int GetSpirit() const { return spirit; }
    void SetSpirit(int newSpirit) { spirit = newSpirit; }

    int GetSpellPower() const { return spellPower; }
    void SetSpellPower(int newSpellPower) { spellPower = newSpellPower; }

    int GetArmor() const { return armor; }
    void SetArmor(int newArmor) { armor = newArmor; }

    int GetResilience() const { return resilience; }
    void SetResilience(int newResilience) { resilience = newResilience; }

    int GetDefense() const { return defense; }
    void SetDefense(int newDefense) { defense = newDefense; }

    int GetDodge() const { return dodge; }
    void SetDodge(int newDodge) { dodge = newDodge; }

    int GetParry() const { return parry; }
    void SetParry(int newParry) { parry = newParry; }

    int GetBlock() const { return block; }
    void SetBlock(int newBlock) { block = newBlock; }

    int GetHaste() const { return haste; }
    void SetHaste(int newHaste) { haste = newHaste; }

    int GetCrit() const { return crit; }
    void SetCrit(int newCrit) { crit = newCrit; }

    int GetHit() const { return hit; }
    void SetHit(int newHit) { hit = newHit; }

    int GetExpertise() const { return expertise; }
    void SetExpertise(int newExpertise) { expertise = newExpertise; }

    int GetSpellCrit() const { return spellCrit; }
    void SetSpellCrit(int newSpellCrit) { spellCrit = newSpellCrit; }

    int GetDamagePerSecond() const { return damagePerSecond; }
    void SetDamagePerSecond(int newDPS) { damagePerSecond = newDPS; }

    int GetHealingPerSecond() const { return healingPerSecond; }
    void SetHealingPerSecond(int newHPS) { healingPerSecond = newHPS; }

    int GetArmorPenetration() const { return armorPenetration; }
    void SetArmorPenetration(int newArmorPen) { armorPenetration = newArmorPen; }
};

#endif /* Entity_h */
