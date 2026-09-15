#ifndef STAFF_H
#define STAFF_H
#include <string.h>
#include <unordered_map>
#include <iostream>
#include "accessories.h"

class Task
{
    enum task_state
    {
        Start,
        Pause,
        Resume,
        Finished
    };
    task_state state = Start;
protected:
    task_state getStatus() { return state; }
    void setStatus(task_state state) { this->state = state; }
};

class Staff
{

public:
    Staff();
    int id;
    enum class Designations {
        Manager,
        Waiter,
        Cashier,
        Chef,
        Dishwasher,
    };

    enum class Coordinate {

    };
    virtual Designations myDesignation() = 0;
    virtual std::string myJob() = 0;
    virtual int salary() = 0;
protected:
    Accessories accessories;
};

class Waiter : public Staff
{
public:

};

class Manager : public Staff
{
    public:
    Designations myDesignation() override;
    std::string myJob() override;
    int salary() override;
};

#endif // STAFF_H
