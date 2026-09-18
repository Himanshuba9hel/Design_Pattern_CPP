#include "room.h"

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

Kitchen::Kitchen(unsigned int area, Staff staff)
{
    this->area = area;
    location = Location::Kitchen;
}
