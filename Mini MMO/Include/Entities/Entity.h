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
    
    static std::unique_ptr<Resource> createResource(InGameClassType classType) {
       switch (classType) {
           case InGameClassType::Rogue:
               return std::make_unique<Energy>(100);
           case InGameClassType::Mage:
               return std::make_unique<Mana>(150);
           case InGameClassType::Warrior:
               return std::make_unique<Rage>(100);
           default:
               throw std::invalid_argument("Invalid class type");
       }
    }
    
    void initializeClassSpells(InGameClassType classType) {
        switch (classType) {
            case InGameClassType::Mage:
                // spellBook.push_back(std::make_unique<Fireball>());
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
    }
    
    void castSpell(int spellIndex) {
        if (spellIndex < 0 || spellIndex >= spellBook.size()) {
            throw std::out_of_range("Invalid spell index");
        }

        auto& spell = spellBook[spellIndex];
        if (resource->getCurrentAmount() >= spell->getResourceCost()) {
            spell->cast();
            resource->consume(spell->getResourceCost());
        } else {
            std::cout << "Not enough resource to cast " << spell->getName() << "!\n";
        }
    }
    
    void initializeClassProperties(InGameClassType classType) {
        switch (classType) {
            case InGameClassType::Mage:
                strength = 5;
                agility = 10;
                stamina = 10;
                intellect = 30;
                spirit = 25;
                spellPower = 60;
                // Add other stats and abilities...
                break;
            case InGameClassType::Rogue:
                strength = 10;
                agility = 20;
                stamina = 15;
                intellect = 5;
                spirit = 8;
                attackPower = 50;
                // Add other stats and abilities...
                break;
            case InGameClassType::Warrior:
                strength = 20;
                agility = 10;
                stamina = 25;
                intellect = 5;
                spirit = 8;
                defense = 30;
                // Add other stats and abilities...
                break;
            default:
                throw std::invalid_argument("Invalid class type");
        }
    }
    
public:
    Entity(const std::string& entityName, int entityLevel, InGameClassType classType)
        : name(entityName), level(entityLevel), inGameClassType(classType) {
            
        // Initialize resource based on in-game class type
        resource = createResource(classType);
        initializeClassProperties(classType);
        spellBook = SpellFactory::createSpells(classType);
    }
    
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
