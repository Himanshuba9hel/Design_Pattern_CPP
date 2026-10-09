#include <iostream>

// Base class for shapes
class Rectangle {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    virtual double area() const {
        return width * height;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    virtual void setWidth(double w) {   // made virtual
        width = w;
    }

    virtual void setHeight(double h) {  // also virtual (good practice)
        height = h;
    }
};

// Derived class for squares
class Square : public Rectangle {
public:
    Square(double size) : Rectangle(size, size) {}

    void setWidth(double w) override {
        width = height = w;
    }

    void setHeight(double h) override {
        width = height = h;
    }
};

int main() {
    Square s(5);
    s.setWidth(10);
    std::cout << "Area: " << s.area() << std::endl;
    return 0;
}