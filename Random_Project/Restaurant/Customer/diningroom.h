#ifndef DININGROOM_H
#define DININGROOM_H
#include <unordered_map>

class Table;

class DiningRoom
{
public:
    DiningRoom();
};

class Customer;

class Table
{
public:
    Table(unsigned int maximum_chairs);
    std::unordered_map<unsigned int, Customer*> chairs_customer_arrangement;
}

#endif // DININGROOM_H
