#include <iostream>
#include "shapes.h"

using namespace std;
/*
 *  "The single responsibility principle states that every
 *  module or class should have responsibility over a single
 *  part of the functionality provided by the software,
 *  and that responsibility should be entirely encapsulated
 *  by the class, module or function. All its services should
 *  be narrowly aligned with that responsibility."
 *  (Wikipedia)"
 *
 *
 *
 *  "Orthogonality: ... We want to design components that
 *  are self- contained: independent, and with a single,
 *  well-defined purpose ([...] cohesion). When components
 *  are isolated from one another, you know that you can
 *  change one without having to worry about the rest.”
 *  (Andrew Hunt, David Thomas, The Pragmatic Programmer)
 */

int main()
{
    cout << "Hello World!" << endl;
    Square mySquare(23);
    mySquare.showSide();
    mySquare.setLocation(23,34);
    mySquare.showLocation();
    Circle myCircle(12);
    myCircle.showSide();
    return 0;
}
