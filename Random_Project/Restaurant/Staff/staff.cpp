#include "staff.h"
#include "../Restaurants/restaurants.h"

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


Waiter::Waiter()
{
    ID  = varID++;
    designation = Designations::Waiter;
    salary  = 25,000;
    location = Location::Dining_Room;
}


std::string Waiter::myJob()
{
    return "To handle customers.";
}
