#ifndef Rage_h
#define Rage_h

#include "Resource.h"

class Rage : public Resource {
public:
    Rage(int max);
    
    void consume(int amount) override;
    void regenerate(int amount) override;
};

#endif
