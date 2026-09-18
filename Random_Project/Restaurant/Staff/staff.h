#ifndef STAFF_H
#define STAFF_H
#include <string.h>
#include <unordered_map>
#include <iostream>
#include "accessories.h"

// class Restaurants;
class DiningRoom;
class Task;
class Room;
enum class Designations;
enum class Location;

static unsigned int varID = 0;
class Staff
{
public:
    Staff();

// Identification Data
protected:
    unsigned int ID;
    Designations designation;
    unsigned int salary;
public:
    virtual Designations myDesignation() = 0;
    virtual std::string myJob() = 0;
    virtual int mysalary() = 0;

// Position
protected:
    Room* room = nullptr;
    Location location;
public:
    // virtual setRoom(Room* room) = 0;

// Restaurant Data
protected:
    DiningRoom* dining_room = nullptr;
    virtual void task() = 0;

};

enum class Designations {
    Manager,
    Waiter,
    Cashier,
    Chef,
    Dishwasher,
};


class Waiter : public Staff
{
public:
    Waiter(DiningRoom* dining_room);

public:
    Designations myDesignation() override { return designation; }
    std::string myJob() override;
    int mysalary() override { return salary; }
// His Job
    void task() override;
};


class Manager : public Staff
{
public:
    Manager();

public:
    Designations myDesignation() override { return designation; }
    std::string myJob() override;
    int mysalary() override { return salary; }
};




class Cashier: public Staff
{
public:
    Cashier();

public:
    Designations myDesignation() override { return designation; }
    std::string myJob() override;
    int mysalary() override { return salary; }
};


class Dishwasher: public Staff
{
public:
    Dishwasher();

public:
    Designations myDesignation() override { return designation; }
    std::string myJob() override;
    int mysalary() override { return salary; }
};


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
#endif // STAFF_H
