#ifndef Resource_h
#define Resource_h

class Resource {
protected:
    int maxAmount;
    int currentAmount;

public:
    Resource(int max);
    virtual ~Resource() = default;

    virtual void consume(int amount);
    virtual void regenerate(int amount);

    int getCurrentAmount() const { return currentAmount; }
    int getMaxAmount() const { return maxAmount; }
};

#endif
