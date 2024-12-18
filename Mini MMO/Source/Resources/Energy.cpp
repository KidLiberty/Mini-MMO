#include <algorithm>

#include "../../Include/Resources/Energy.h"

Energy::Energy(int max) : Resource(max) {};

void Energy::consume(int amount) {
    // Custom logic for consuming Energy
    if (amount > getCurrentAmount()) {
        currentAmount = 0; // Or handle other under-consumption logic
    } else {
        currentAmount -= amount;
    }
}

void Energy::regenerate(int amount) {
    // Custom logic for regenerating Energy
    currentAmount = std::min(getMaxAmount(), currentAmount + amount);
}
