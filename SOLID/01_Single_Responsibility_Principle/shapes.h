#ifndef SHAPES_H
#define SHAPES_H

#include <vector>

class Shapes
{
public:
    Shapes();
};

class Dimension
{
protected:
    std::vector<unsigned int> sides;
public:
    Dimension(std::vector<unsigned int> initial_sides);
    Dimension(unsigned int no_sides);
    Dimension(unsigned int no_sides, unsigned int side_length);
    virtual void showSide() final;

protected:
    std::pair<int,int> location = {0,0};
public:
    virtual void setLocation(int x, int y) final;
    virtual std::pair<int,int> getLocation() final;
    virtual void showLocation() final;

protected:
    unsigned int area = 0;
};

class Circle : public Dimension
{
protected:

public:
    Circle(unsigned int radius);

};

class Square : public Dimension
{
protected:

public:
    Square(unsigned int equal_side_length);
};

#endif // SHAPES_H
