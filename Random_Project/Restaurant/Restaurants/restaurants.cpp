#include "restaurants.h"
#include "../Customer/customer.h"
#include "../Customer/diningroom.h"
#include "../Staff/staff.h"

Restaurants::Restaurants()
{
    TableNChair empty_table_n_chair = {.Tables = 0,.Chairs = 0};
    std::vector<TableNChair> emptr_room = {empty_table_n_chair};
    dining_room = new DiningRoom(&emptr_room);
}

struct Restaurants_Specification{
    std::vector<TableNChair> *table_n_chairs;
    std::vector<Staff*> *staff_list;
    std::vector<Customer*> *customers;
};
Restaurants::Restaurants(Restaurants_Specification specification)
{
    dining_room = new DiningRoom(specification.table_n_chairs);
    addStaff(specification.staff_list);
    // addCustomer(specification.customers);
}


void Restaurants::customerEntry(Customer *customer)
{
    customer->enteredInRestaurant();
}

void Restaurants::addStaff(Staff *staff)
{
    switch(staff->myDesignation()){
    case Designations::Cashier:
        break;
    case Designations::Chef:
        break;
    case Designations::Waiter:
        addWaiter(dynamic_cast<Waiter*>(staff));
        break;
    case Designations::Manager:
        // addManager(dynamic_cast<Manager*>(staff));
        break;
    case Designations::Dishwasher:
        break;
    }
}

void Restaurants::addStaff(std::vector<Staff*> *staff)
{
    if(!staff) return;

    for(auto staff_member = staff->begin();
        staff_member != staff->end(); ++staff_member)
    {
        if((*staff_member) == nullptr) break;

        switch((*staff_member)->myDesignation())
        {
        case Designations::Cashier:
            break;
        case Designations::Chef:
            break;
        case Designations::Waiter:
            addWaiter(dynamic_cast<Waiter*>(*staff_member));
            break;
        case Designations::Manager:
            // addManager(dynamic_cast<Manager*>(*staff_member));
            break;
        case Designations::Dishwasher:
            break;
        }
    }
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
