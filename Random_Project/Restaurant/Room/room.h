#ifndef ROOM_H
#define ROOM_H
#include <unordered_set>
class Staff;
class Object;

enum class Location {
    CashCounter,
    DinningRoom,
    Kitchen,
    WaitingArea,
    WashRoom
};

class Room
{
public:
    Room(unsigned int area);

// Area of Room
protected:
    unsigned int area = 0;
    virtual void setArea(unsigned int area) final;
    virtual unsigned int getArea() final;

// Occupying area
// Objects
    std::unordered_set<Object*> objects;
    virtual void setObject(Object* object) final;

    virtual void getWalkingArea() final;
// Location
    Location location;
};

class Kitchen : public Room
{
public:
    Kitchen(unsigned int area, Staff staff);

// Kitchen
protected:

};

#endif // ROOM_H
