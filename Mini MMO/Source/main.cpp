#include <iostream>
#include <memory>

#include "../Include/Entities/Entity.h"
#include "../Include/Entities/Creature.h"
#include "../Include/InGameClasses/InGameClassType.h"

int main() {
    std::unique_ptr<Entity> entity = std::make_unique<Entity>("Ackeron", 10, InGameClassType::Rogue);
    std::unique_ptr<Entity> entityTwo = std::make_unique<Creature>(1, "Defias Pillager", 10, InGameClassType::Mage);
    entity->castSpell(0, entityTwo.get());
    return 0;
}
