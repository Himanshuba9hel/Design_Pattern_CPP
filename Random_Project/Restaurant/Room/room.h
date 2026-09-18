#ifndef ROOM_H
#define ROOM_H

class Staff;

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
