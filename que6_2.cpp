#include <iostream>
#include <stdexcept>
using namespace std;

// Function to perform division
double divideNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero is not allowed!");
    }
    return numerator / denominator;
}

int main() {
    double num1, num2;
    
    try {
        // Get input from user
        cout << "Enter the first number: ";
        cin >> num1;
        
        cout << "Enter the second number: ";
        cin >> num2;
        
        // Perform division
        double result = divideNumbers(num1, num2);
        cout << "Result: " << result << endl;
        
    } catch (const runtime_error& e) {
        // Handle division by zero
        cout << "Error: " << e.what() << endl;
    } catch (...) {
        // Handle any other unexpected errors
        cout << "An unexpected error occurred!" << endl;
    }
    
    return 0;
}