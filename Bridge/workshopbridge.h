#ifndef WORKSHOPBRIDGE_H
#define WORKSHOPBRIDGE_H
#include <iostream>
using namespace std;

class WorkshopBridge
{
public:
    WorkshopBridge();
};

class Workshop
{
public:
    virtual void work() = 0;
};

class Assemble : public Workshop
{
public:
    void work() override {
        cout<< "Assemble"<<endl;
    }
};

class Produce : public Workshop
{
public:
    void work() override {
        cout<< "Produce"<<endl;
    }
};

class Vehicle
{
protected:
    Workshop* workshop1;
    Workshop* workshop2;
public:
    Vehicle(Workshop* workshop1, Workshop* workshop2){
        this->workshop1 = workshop1;
        this->workshop2 = workshop2;
    }
    virtual void manufacture() = 0;
};

class Car : public Vehicle
{
public:
    Car(Workshop* workshop1, Workshop* workshop2): Vehicle(workshop1,workshop2) {}
    void manufacture() override {
        cout<<"Car"<<endl;
        workshop1->work();
        workshop2->work();
    }
};

class Bike : public Vehicle
{
public:
    Bike(Workshop* workshop1, Workshop* workshop2): Vehicle(workshop1,workshop2) {}
    void manufacture() override {
        cout<<"Bike"<<endl;
        workshop1->work();
        workshop2->work();
    }
};
#endif // WORKSHOPBRIDGE_H
