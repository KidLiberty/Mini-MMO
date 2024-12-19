#include <iostream>
#include <memory>

#include "../Include/Entities/Entity.h"
#include "../Include/InGameClasses/InGameClassType.h"

int main() {
    std::unique_ptr<Entity> entity = std::make_unique<Entity>("Ackeron", 1, InGameClassType::Mage);
    // entity->castSpell(0);
    std::cout << entity->getIntellect() << std::endl;
    return 0;
}
