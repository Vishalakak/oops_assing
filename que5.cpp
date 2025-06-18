#include <iostream>
#include <string>
#include <cmath>   
#include <cstdlib>
using namespace std;

class Complex {
private:
    double real;
    double imag;
    
public:
    // Default constructor
    Complex() : real(0), imag(0) {}
    
    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}
    
    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    
    // Display complex number
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << abs(imag) << "i" << endl;
    }
};

int main() {
    // Create complex numbers
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    
    cout << "Complex number 1: ";
    c1.display();
    
    cout << "Complex number 2: ";
    c2.display();
    
    // Add complex numbers using + operator
    Complex sum = c1 + c2;
    cout << "Sum: ";
    sum.display();
    
    // Subtract complex numbers using - operator
    Complex difference = c1 - c2;
    cout << "Difference: ";
    difference.display();
    
    return 0;
}