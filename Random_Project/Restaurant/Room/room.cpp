#include "room.h"
#include "object.h"

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

Kitchen::Kitchen(unsigned int area, Staff staff)
{
    this->area = area;
    location = Location::Kitchen;
}
