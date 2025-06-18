#include <iostream>
using namespace std;

class Box {
private:
    double length;
    double breadth;
    double height;
    
public:
    // Default constructor
    Box() {
        cout << "Default constructor called" << endl;
        length = breadth = height = 0.0;
    }
    
    // Parameterized constructor
    Box(double l, double b, double h) {
        cout << "Parameterized constructor called" << endl;
        length = l;
        breadth = b;
        height = h;
    }
    
    // Copy constructor
    Box(const Box& other) {
        cout << "Copy constructor called" << endl;
        length = other.length;
        breadth = other.breadth;
        height = other.height;
    }
    
    // Destructor
    ~Box() {
        cout << "Destructor called" << endl;
    }
    
    // Method to calculate volume
    double calculateVolume() {
        return length * breadth * height;
    }
};

int main() {
    // Creating box1 using default constructor
    Box box1;
    
    // Creating box2 using parameterized constructor
    Box box2(5.0, 3.0, 2.0);
    
    // Creating box3 using copy constructor
    Box box3(box2);
    
    // Display volumes
    cout << "\nVolumes:" << endl;
    cout << "box1 volume: " << box1.calculateVolume() << endl;
    cout << "box2 volume: " << box2.calculateVolume() << endl;
    cout << "box3 volume: " << box3.calculateVolume() << endl;
    
    return 0;
}