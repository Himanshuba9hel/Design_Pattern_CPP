#include "shapes.h"

Shapes::Shapes() {}

// 1. Base class constructor takes the input and fills the vector
Dimension::Dimension(std::vector<unsigned int> initial_sides) :
    sides(initial_sides)
{
}

Dimension::Dimension(unsigned int no_sides) :
    sides(no_sides, 1)
{
}

Dimension::Dimension(unsigned int no_sides, unsigned int side_length) :
    sides(no_sides, side_length)
{
}
