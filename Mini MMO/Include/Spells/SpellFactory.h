#include <memory>
#include <vector>

#include "Spell.h"

class SpellFactory {
public:
    static std::vector<std::unique_ptr<Spell>> createSpells(InGameClassType classType);
};
