#include <stdexcept>

#include "../../Include/Entities/Entity.h"
#include "../../Include/Resources/Resource.h"

Entity::Entity(const std::string& name, int level, InGameClassType type)
    : name(name), level(level), inGameClassType(type) {
    
    // Initialize resource based on in-game class type
    resource = createResource(type);
    initializeClassProperties(type);
    spellBook = SpellFactory::createSpells(type);
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
        case InGameClassType::Hunter:
            health = 60;
            strength = 7;
            agility = 18;
            stamina = 10;
            intellect = 15;
            spirit = 12;
            spellPower = 60;
            // Add other stats and abilities...
            break;
        case InGameClassType::Mage:
            health = 50;
            strength = 5;
            agility = 10;
            stamina = 10;
            intellect = 30;
            spirit = 25;
            spellPower = 60;
            break;
        case InGameClassType::Rogue:
            health = 80;
            strength = 10;
            agility = 20;
            stamina = 15;
            intellect = 5;
            spirit = 8;
            attackPower = 50;
            break;
        case InGameClassType::Warrior:
            health = 120;
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
        
        std::cout << name << " casts " << spell->getName() <<  " on " << target->getName() << "." << std::endl;
        spell->cast(*this, target);
    } else {
        std::cout << "Not enough resource to cast " << spell->getName() << "!" << std::endl;
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
    
    std::cout << name << " takes " << amount << " damage." << std::endl;
    
    if(health == 0) {
        die();
    }
}

void Entity::die() {
    if(health <= 0) {
        std::cout << name << " dies." << std::endl;
        spellBook.clear();
    }
}
