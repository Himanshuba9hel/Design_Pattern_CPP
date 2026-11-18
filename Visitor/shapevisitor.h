#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H

class Circle;
class Square;
class Triangle;

// Visitor interface
class ShapeVisitor {
public:
    virtual void visit(Circle* circle) = 0;
    virtual void visit(Square* square) = 0;
    virtual void visit(Triangle* triangle) = 0;
};

// Element interface
class Shape {
public:
    virtual void accept(ShapeVisitor* visitor) = 0;
    virtual ~Shape() {}
};

// Concrete Elements
class Circle : public Shape {
public:
    void accept(ShapeVisitor* visitor) override {
        visitor->visit(this);
    }
};

class Square : public Shape {
public:
    void accept(ShapeVisitor* visitor) override {
        visitor->visit(this);
    }
};

class Triangle : public Shape {
public:
    void accept(ShapeVisitor* visitor) override {
        visitor->visit(this);
    }
};

// Concrete Visitor
class AreaCalculator : public ShapeVisitor {
private:
    double totalArea = 0;

public:
    void visit(Circle* circle) override {
        double radius = 5;
        totalArea += M_PI * radius * radius;
    }

    void visit(Square* square) override {
        double side = 4;
        totalArea += side * side;
    }

    void visit(Triangle* triangle) override {
        double base = 3;
        double height = 6;
        totalArea += (base * height) / 2;
    }

    double getTotalArea() {
        return totalArea;
    }
};




#endif // SHAPEVISITOR_H
