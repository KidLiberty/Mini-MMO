#ifndef Fireball_h
#define Fireball_h

#include <iostream>

#include "Spell.h"

class Fireball : public Spell {
public:
    Fireball() : Spell("Fireball", 20, 50) {} // Example values

    void cast() const override {
        std::cout << "Casting " << name << " for " << damage << " damage!\n";
    }
};

#endif
