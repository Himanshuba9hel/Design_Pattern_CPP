#include "shapes.h"
#include <iostream>

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

void Dimension::showSide()
{
    std::cout<<"Sides: {";
    std::size_t index = 0;
    for(auto side = sides.begin(); side != sides.end(); ++side, ++index){
        std::cout<<" "<<index<<": "<<*side<<",";
    }
    std::cout<<"}"<<std::endl;
}

void Dimension::setLocation(int x = 0, int y = 0)
{
    location.first = x;
    location.second = y;
}

std::pair<int, int> Dimension::getLocation()
{
    return {location.first, location.second};
}

void Dimension::showLocation()
{
    std::cout<<"Location : { "
        <<"x: "<<location.first<<", "
        <<"y: "<<location.second<<" }"<<std::endl;
}

Circle::Circle(unsigned int radius) : Dimension(1 , radius) // Passes {0} to Dimension
{

}

Square::Square(unsigned int equal_side_length) : Dimension( 2, equal_side_length) // Passes {0} to Dimension
{
    // If you delete ": Dimension({0})", you get a Compiler Error!
}