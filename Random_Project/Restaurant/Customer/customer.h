#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <unordered_map>
#include <string>

enum class Location;
class Customer
{
public:
    Customer();
    enum class Customer_Type {
        Regular,
        New,
        Old,
        Critic,
        Allergy,
        Food_Inspector
    };
    // Identity
    std::unordered_map<Customer_Type,std::string> Customer_Type_Name;
    // Position
protected:
    Location location;
public:
    void enteredInRestaurant();
    void exitFromRestaurant();

    Customer_Type virtual type() = 0;
    void virtual lifeCycle();
};

class Regular : public Customer
{
    Customer_Type type() override { return Customer_Type::Regular;}
};

class Old : public Customer
{
    Customer_Type type() override { return Customer_Type::Old;}
};

class New : public Customer
{
    Customer_Type type() override { return Customer_Type::New;}
};

#endif // CUSTOMER_H
