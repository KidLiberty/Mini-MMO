#include <algorithm>

#include "../../Include/Resources/Mana.h"

Mana::Mana(int max) : Resource(max) {}

void Mana::consume(int amount) {
    if(amount > getCurrentAmount()) {
        currentAmount = 0;
    } else {
        currentAmount -= amount;
    }
}

void Mana::regenerate(int amount) {
    // Custom logic for regenerating Energy
    currentAmount = std::min(getMaxAmount(), currentAmount + amount);
}
