#include <iostream>

#include "../../Include/Resources/Resource.h"
#include "../../Include/Spells/Fireball.h"

Fireball::Fireball() : Spell("Fireball", 20, 50) {} 

//void Fireball::cast(Resource& resource) const {
//   if (resource.getCurrentAmount() >= getResourceCost()) {
//       // Perform casting logic
//       std::cout << "Casting " << getName() << " for " << getDamage() << " damage!\n";
//       resource.consume(getResourceCost());
//   } else {
//       std::cout << "Not enough resource to cast " << getName() << "!\n";
//   }
//}
