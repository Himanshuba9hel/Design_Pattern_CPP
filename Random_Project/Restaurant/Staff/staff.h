#ifndef STAFF_H
#define STAFF_H
#include <string.h>
#include <unordered_map>
#include <iostream>

class Staff
{
public:
    Staff();
    enum class Designations {
        Manager,
        Waiter,
        Cashier,
        Chef,
        Dishwasher
    };

    enum class Coordinate {

    };
    virtual Designations myDesignation() = 0;
    virtual std::string myJob() = 0;
    virtual int salary() = 0;
};

class Manager : public Staff
{
    public:
    Designations myDesignation() override;
    std::string myJob() override;
    int salary() override;
};

#endif // STAFF_H
