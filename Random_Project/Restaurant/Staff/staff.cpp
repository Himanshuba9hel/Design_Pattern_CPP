#include "staff.h"
#include "../Restaurants/restaurants.h"
#include "../Customer/diningroom.h"

Staff::Staff() {

}


Manager::Manager()
{
    ID  = varID++;
    designation = Designations::Manager;
    salary  = 30,000;
    location = Location::Cabin;
}


std::string Manager::myJob()
{
    return "I manage all the staff";
}


Waiter::Waiter(DiningRoom* dining_room)
{
    ID  = varID++;
    designation = Designations::Waiter;
    salary  = 25,000;
    location = Location::Dining_Room;
    this->dining_room = dining_room;
}

std::string Waiter::myJob()
{
    return "To handle customers.";
}

void Waiter::task()
{

}
