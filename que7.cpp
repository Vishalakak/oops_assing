#include <iostream>
#include <stdexcept>
using namespace std;

// Function that throws an exception
void divideNumbers(int numerator, int denominator) {
    try {
        if (denominator == 0) {
            throw runtime_error("Division by zero is not allowed!");
        }
        int result = numerator / denominator;
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cout << "In divideNumbers(): Caught exception - " << e.what() << endl;
        // Rethrow the exception to handle it at a higher level
        throw;
    }
}

// Function that calls divideNumbers and catches the re-thrown exception
void calculate(int numerator, int denominator) {
    try {
        cout << "Attempting division..." << endl;
        divideNumbers(numerator, denominator);
    }
    catch (const exception& e) {
        cout << "In calculate(): Caught re-thrown exception - " << e.what() << endl;
        // Handle the exception at this level
        cout << "Taking appropriate action at calculate() level..." << endl;
    }
}

int main() {
    try {
        cout << "Starting program..." << endl;
        calculate(10, 0);
    }
    catch (const exception& e) {
        cout << "In main(): Final exception handling - " << e.what() << endl;
        cout << "Program execution completed." << endl;
    }
    
    return 0;
}