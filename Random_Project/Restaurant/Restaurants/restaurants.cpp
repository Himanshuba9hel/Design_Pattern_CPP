#include "restaurants.h"
#include "../Customer/customer.h"
#include "../Customer/diningroom.h"
#include "../Staff/staff.h"

Restaurants::Restaurants()
{

}

void Restaurants::customerEntry(Customer *customer)
{
    customer->enteredInRestaurant();
}

void Restaurants::addWaiter(Waiter *waiter)
{
    waiters.insert(waiter);
}

void Restaurants::addCustomer(Customer *customer)
{
    customers.insert(customer);
}

RestaurantsSchedule::RestaurantsSchedule()
{

}
