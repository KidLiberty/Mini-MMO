//
//  InGameClass.h
//  Mini MMO
//
//  Created by Brandon Stone on 12/18/24.
//

#ifndef InGameClass_h
#define InGameClass_h
#include "../Entities/Entity.h"

// Base InGameClass class
class InGameClass {
protected:
    int resourceType;  // Energy, Mana, Rage, etc.
    int statModifiers; // Buffs, debuffs, enhancements to the Entity's stats
public:
   // virtual void ApplyClassMechanics(Entity& entity) = 0; // Pure virtual function
};

#endif /* InGameClass_h */
