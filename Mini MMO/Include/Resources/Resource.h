//
//  Resource.h
//  Mini MMO
//
//  Created by Brandon Stone on 12/18/24.
//

class Resource {
protected:
    int maxAmount;
    int currentAmount;

public:
    Resource(int max);
    virtual ~Resource() = default;

    virtual void Consume(int amount);
    virtual void Regenerate(int amount);

    int GetCurrentAmount() const { return currentAmount; }
    int GetMaxAmount() const { return maxAmount; }
};
