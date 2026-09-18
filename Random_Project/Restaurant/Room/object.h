#ifndef OBJECT_H
#define OBJECT_H

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
};



#endif // OBJECT_H
