#ifndef Entity_h
#define Entity_h

#include <string>
#include <vector>
#include <memory>

#include "../InGameClasses/InGameClass.h"
#include "../InGameClasses/InGameClassType.h"
#include "../Resources/Energy.h"
#include "../Resources/Mana.h"
#include "../Resources/Rage.h"
#include "../Resources/Resource.h"
#include "../Spells/Spell.h"
#include "../Spells/SpellFactory.h"
#include "../Spells/Fireball.h"
#include "../Spells/Eviscerate.h"

class Entity {
private:
    std::string name;
    const InGameClassType inGameClassType;
    int level;
    int health;
    std::vector<std::unique_ptr<Spell>> spellBook;
    std::unique_ptr<Resource> resource;
    
    float movementSpeed = 10.0f;
    
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
    
    static std::unique_ptr<Resource> createResource(InGameClassType classType);
    
    void initializeClassSpells(InGameClassType classType);
    void initializeClassProperties(InGameClassType classType);
    
public:
    Entity(const std::string& entityName, int entityLevel, InGameClassType classType);
    
    void castSpell(int spellIndex, std::unique_ptr<Resource>& resource);
    
    // TODO: Implement a getter & setter for Resource
    // const Resource* getResource() const { return resource; }
    
    const std::string& getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }
    
    const InGameClassType getInGameClassType() const { return inGameClassType; }

    int getLevel() const { return level; }
    void setLevel(int newLevel) { level = newLevel; }

    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = newHealth; }

    int getAttackPower() const { return attackPower; }
    void setAttackPower(int newAttackPower) { attackPower = newAttackPower; }

    float getMovementSpeed() const { return movementSpeed; }
    void setMovementSpeed(float newSpeed) { movementSpeed = newSpeed; }

    int getStrength() const { return strength; }
    void setStrength(int newStrength) { strength = newStrength; }

    int getAgility() const { return agility; }
    void setAgility(int newAgility) { agility = newAgility; }

    int getStamina() const { return stamina; }
    void setStamina(int newStamina) { stamina = newStamina; }

    int getIntellect() const { return intellect; }
    void setIntellect(int newIntellect) { intellect = newIntellect; }

    int getSpirit() const { return spirit; }
    void setSpirit(int newSpirit) { spirit = newSpirit; }

    int getSpellPower() const { return spellPower; }
    void setSpellPower(int newSpellPower) { spellPower = newSpellPower; }

    int getArmor() const { return armor; }
    void setArmor(int newArmor) { armor = newArmor; }

    int getResilience() const { return resilience; }
    void setResilience(int newResilience) { resilience = newResilience; }

    int getDefense() const { return defense; }
    void setDefense(int newDefense) { defense = newDefense; }

    int getDodge() const { return dodge; }
    void setDodge(int newDodge) { dodge = newDodge; }

    int getParry() const { return parry; }
    void setParry(int newParry) { parry = newParry; }

    int getBlock() const { return block; }
    void setBlock(int newBlock) { block = newBlock; }

    int getHaste() const { return haste; }
    void setHaste(int newHaste) { haste = newHaste; }

    int getCrit() const { return crit; }
    void setCrit(int newCrit) { crit = newCrit; }

    int getHit() const { return hit; }
    void setHit(int newHit) { hit = newHit; }

    int getExpertise() const { return expertise; }
    void setExpertise(int newExpertise) { expertise = newExpertise; }

    int getSpellCrit() const { return spellCrit; }
    void setSpellCrit(int newSpellCrit) { spellCrit = newSpellCrit; }

    int getDamagePerSecond() const { return damagePerSecond; }
    void setDamagePerSecond(int newDPS) { damagePerSecond = newDPS; }

    int getHealingPerSecond() const { return healingPerSecond; }
    void setHealingPerSecond(int newHPS) { healingPerSecond = newHPS; }

    int getArmorPenetration() const { return armorPenetration; }
    void setArmorPenetration(int newArmorPen) { armorPenetration = newArmorPen; }

};

#endif
