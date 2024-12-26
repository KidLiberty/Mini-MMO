#ifndef Item_h
#define Item_h

#include <string>
#include "ItemQuality.h"

class Item {
private:
    std::string name;
    ItemQuality quality;
public:
    Item(const std::string& name, ItemQuality quality);
    
    std::string getName() const { return name; }
};

#endif 
