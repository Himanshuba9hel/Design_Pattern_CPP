#ifndef LAND_H
#define LAND_H
#include <list>

class Land
{
public:
    virtual unsigned int getArea() = 0;
    virtual unsigned int getLength() = 0;
    virtual unsigned int getBreadth() = 0;
    virtual void setLength(unsigned int length) = 0;
    virtual void setBreadth(unsigned int breadth) = 0;
    virtual bool isComposite() const {
        return true;
    }
    virtual std::list<Land*> getLandList();
};

class Locality : public Land
{
private:
    int length = 0, breadth = 0;
public:
    unsigned int getArea()    override { return length;       }
    unsigned int getLength()  override { return breadth;       }
    unsigned int getBreadth() override { return length*breadth;}
    void setLength (unsigned int length)  override { this->length   = length;  }
    void setBreadth(unsigned int breadth) override { this->breadth  = breadth; }
    bool isComposite() const override{
        return false;
    }
};

class Plot : public Land
{
private:
    int length = 0, breadth = 0;
public:
    Plot(unsigned int length, unsigned int breadth) {
        this->length   = length;
        this->breadth  = breadth;
    }
    unsigned int getArea()    override { return length;       }
    unsigned int getLength()  override { return breadth;       }
    unsigned int getBreadth() override { return length*breadth;}
    void setLength (unsigned int length)  override { this->length   = length;  }
    void setBreadth(unsigned int breadth) override { this->breadth  = breadth; }
    bool isComposite() const override{
        return false;
    }
};
#endif // LAND_H
