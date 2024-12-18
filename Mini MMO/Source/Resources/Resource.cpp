//
//  Resource.cpp
//  Mini MMO
//
//  Created by Brandon Stone on 12/18/24.
//

#include <algorithm>
#include "../../Include/Resources/Resource.h"

Resource::Resource(int max) : maxAmount(max), currentAmount(max) {}

void Resource::consume(int amount) {
    currentAmount = std::max(0, currentAmount - amount);
}

void Resource::regenerate(int amount) {
    currentAmount = std::min(maxAmount, currentAmount + amount);
}
