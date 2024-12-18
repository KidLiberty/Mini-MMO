#include <algorithm>

#include "../../Include/Resources/Rage.h"

Rage::Rage(int max) : Resource(max) {}

void Rage::consume(int amount) {
    if(amount > getCurrentAmount()) {
        currentAmount = 0;
    } else {
        currentAmount -= amount;
    }
}

void Rage::regenerate(int amount) {
    // Custom logic for regenerating Energy
    currentAmount = std::min(getMaxAmount(), currentAmount + amount);
}
