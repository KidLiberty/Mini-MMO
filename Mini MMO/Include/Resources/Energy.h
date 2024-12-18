#ifndef Energy_h
#define Energy_h

#include "Resource.h"

class Energy : public Resource {
public:
    Energy(int max);
    
    void consume(int amount) override;
    void regenerate(int amount) override;
};


#endif /* Energy_h */
