#ifndef Header_h
#define Header_h

#include "Resource.h"

class Mana : public Resource {
public:
    Mana(int max);
    
    void consume(int amount);
    void regenerate(int amount);
};

#endif /* Header_h */
