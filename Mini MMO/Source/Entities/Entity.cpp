#include <stdexcept>

#include "../../Include/Entities/Entity.h"
#include "../../Include/Resources/Resource.h"

Entity::Entity(const std::string& entityName, int entityLevel, InGameClassType classType)
    : name(entityName), level(entityLevel), inGameClassType(classType) {
        
    // Initialize resource based on in-game class type
    resource = createResource(classType);
    initializeClassProperties(classType);
    spellBook = SpellFactory::createSpells(classType);
}

std::unique_ptr<Resource> Entity::createResource(InGameClassType classType) {
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

void Entity::initializeClassSpells(InGameClassType classType) {
    switch (classType) {
        case InGameClassType::Mage:
            spellBook.push_back(std::make_unique<Fireball>(1));
            break;
        case InGameClassType::Rogue:
            spellBook.push_back(std::make_unique<Eviscerate>(1));
            break;
        case InGameClassType::Warrior:
            // Add Warrior-specific spells here
            break;
        default:
            throw std::invalid_argument("Invalid class type");
    }
}

void Entity::initializeClassProperties(InGameClassType classType) {
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

void Entity::castSpell(int spellIndex, Entity* target) {
    if (spellIndex < 0 || spellIndex >= spellBook.size()) {
        throw std::out_of_range("Invalid spell index");
    }

    auto& spell = spellBook[spellIndex];
    if (resource->getCurrentAmount() >= spell->getResourceCost()) {
        resource->consume(spell->getResourceCost());
        spell->cast(*this, target); // Pass the caster and the optional target
    } else {
        std::cout << "Not enough resource to cast " << spell->getName() << "!\n";
    }
}

void Entity::takeDamage(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Damage amount cannot be negative");
    }
   
    health -= amount;
    if (health < 0) {
        // Ensure health does not go below zero
        health = 0;
    }
}
