#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <unordered_map>

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
    unordered_map<Customer_Type,std::string> Customer_Type_Name;

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
