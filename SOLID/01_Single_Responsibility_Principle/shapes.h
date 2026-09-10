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
};

class Circle : public Dimension
{
public:
};

class Square
{
public:
};

#endif // SHAPES_H
