#include "staff.h"

Staff::Staff() {}

Staff::Designations Manager::myDesignation()
{
    return Designations::Manager;
}

std::string Manager::myJob()
{
    return "I manage all the staff";
}

int Manager::salary()
{
    return 22000;
}
