#include "customer.h"

Customer::Customer() {
    Customer_Type_Name[Customer_Type::Regular,] = "Regular";
    Customer_Type_Name[Customer_Type::New] = "New";
    Customer_Type_Name[Customer_Type::Old] = "Old";
    Customer_Type_Name[Customer_Type::Critic] = "Critic";
    Customer_Type_Name[Customer_Type::Allergy] = "Allergy";
    Customer_Type_Name[Customer_Type::Food_Inspector] = "Food Inspector";



}

void Customer::lifeCycle()
{
    std::cout<<"Customer Enter"<<std::endl;
}
