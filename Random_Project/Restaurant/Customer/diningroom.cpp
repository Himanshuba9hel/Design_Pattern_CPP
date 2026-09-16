#include "diningroom.h"

DiningRoom::DiningRoom() {}

Table::Table(unsigned int maximum_chairs)
{
    chairs_customer_arrangement.reserve(maximum_chairs);
}
