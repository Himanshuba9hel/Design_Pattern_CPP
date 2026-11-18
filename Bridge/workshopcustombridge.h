#ifndef WORKSHOPCUSTOMBRIDGE_H
#define WORKSHOPCUSTOMBRIDGE_H

#include <iostream>
#include <variant>

using namespace std;

class Vehicle;
class Car;
class Autorickshaw;
class Bike;

std::variant<Car*, Autorickshaw*, Bike*> VehicleType;

class Workshop
{
public:
    virtual void work(Vehicle* vehicle) = 0;
};

class Assemble : public Workshop
{
public:
    void work(Vehicle* vehicle) override {
        cout<< "Assemble"<<endl;
    }
};

class Produce : public Workshop
{
public:
    void work(Vehicle* vehicle) override {
        cout<< "Produce"<<endl;
    }
};

class Wheels : public Workshop
{
public:
    void work(Vehicle* vehicle) override;
};

class Paint : public Workshop
{
public:
    void work(Vehicle* vehicle) override;
};

class WorkshopCustomBridge
{
public:
    WorkshopCustomBridge();
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
        workshop1->work(this);
        workshop2->work(this);
    }
};

class Autorickshaw : public Vehicle
{
public:
    Autorickshaw(Workshop* workshop1, Workshop* workshop2): Vehicle(workshop1,workshop2) {}
    void manufacture() override {
        cout<<"Autorickshaw"<<endl;
        workshop1->work(this);
        workshop2->work(this);
    }
};

class Bike : public Vehicle
{
public:
    Bike(Workshop* workshop1, Workshop* workshop2): Vehicle(workshop1,workshop2) {}
    void manufacture() override {
        cout<<"Bike"<<endl;
        workshop1->work(this);
        workshop2->work(this);
    }
};

#endif // WORKSHOPCUSTOMBRIDGE_H
