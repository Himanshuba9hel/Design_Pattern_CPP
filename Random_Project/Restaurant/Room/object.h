#ifndef OBJECT_H
#define OBJECT_H
#include <unordered_set>

enum class ObjectOperationOutput;
class Object
{
public:
    Object();
protected:
    int unsigned length = 0;
    int unsigned width  = 0;
    int unsigned height = 0;
public:
    virtual int unsigned area() { return length * width; }
    virtual int unsigned volume() { return length * width * height; }
    virtual void application() = 0;

// Object Holding Other Objects

    std::unordered_set<Object*> objects;
    virtual void insertObject(Object* object) = 0;
};
enum class ObjectOperationOutput
{
    Object_Inserted,
    Area_Unavailable

};

class Table : public Object
{
public:
    Table(unsigned int maximum_chairs);
    // std::unordered_map<unsigned int, Customer*> chairs_customer_arrangement;
};

class Chairs : public Object
{

};

#endif // OBJECT_H
