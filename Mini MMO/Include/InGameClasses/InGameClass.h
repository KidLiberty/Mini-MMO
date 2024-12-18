#ifndef InGameClass_h
#define InGameClass_h

#include <memory>

#include "../Entities/Entity.h"
#include "../Resources/Resource.h"

class InGameClass {
protected:
    std::unique_ptr<Resource> resource;
    // Buffs, debuffs, enhancements to the Entity's stats
    int statModifiers;
public:
   // virtual void ApplyClassMechanics(Entity& entity) = 0; // Pure virtual function
};

#endif /* InGameClass_h */
