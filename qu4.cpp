#include <iostream>
using namespace std;

// Base class Shape
class Shape {
public:
    // Function overloading example: calculateArea with different parameters
    double calculateArea(int side) {
        cout << "Calculating area of square..." << endl;
        return side * side;
    }
    
    double calculateArea(int length, int width) {
        cout << "Calculating area of rectangle..." << endl;
        return length * width;
    }
    
    // Virtual function for overriding
    virtual void display() {
        cout << "This is a shape." << endl;
    }
    
    // Virtual destructor (good practice in base classes)
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    // Function overriding: providing specific implementation for Circle
    void display() override {
        cout << "This is a circle with radius " << radius << endl;
    }
    
    // Additional function specific to Circle
    double calculateArea() {
        cout << "Calculating area of circle..." << endl;
        return 3.14159 * radius * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    int length, width;
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    
    // Function overriding: providing specific implementation for Rectangle
    void display() override {
        cout << "This is a rectangle with length " << length 
             << " and width " << width << endl;
    }
};

int main() {
    // Demonstrate function overloading
    Shape shape;
    cout << "Square area: " << shape.calculateArea(5) << endl;
    cout << "Rectangle area: " << shape.calculateArea(4, 6) << endl;
    
    // Demonstrate function overriding
    Circle circle(3.5);
    Rectangle rectangle(4, 5);
    
    cout << "\nPolymorphic behavior:" << endl;
    Shape* shapePtr = &circle;
    shapePtr->display();  // Calls Circle's display()
    
    shapePtr = &rectangle;
    shapePtr->display();  // Calls Rectangle's display()
    
    return 0;
}