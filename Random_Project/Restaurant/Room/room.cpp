#include "room.h"
#include "object.h"
#include "../Staff/staff.h"

Room::Room(unsigned int area)
{
    this->area = area;
}

void Room::setArea(unsigned int area)
{
    this->area = area;
}

unsigned int Room::getArea()
{
    return area;
}

void Room::setObject(Object *object)
{
    objects.insert(object);
}

unsigned int Room::getWalkingArea()
{
    return area;
}

Kitchen::Kitchen(unsigned int area, Staff *staff) : Room(area) // Explicitly initialize the base class
{
    this->area = area;
    location = Location::Kitchen;
}
