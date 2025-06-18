#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Function to demonstrate division by zero exception
double divideNumbers(double num, double den) {
    if (den == 0) {
        throw runtime_error("Division by zero is not allowed!");
    }
    return num / den;
}

// Function to demonstrate invalid input exception
int getValidNumber(const string& prompt) {
    int number;
    cout << prompt;
    if (!(cin >> number)) {
        throw invalid_argument("Invalid input! Please enter a number.");
    }
    return number;
}

int main() {
    try {
        // Try to divide by zero
        cout << "Attempting division by zero:" << endl;
        double result = divideNumbers(10.0, 0.0);
        
    } catch (const runtime_error& e) {
        cout << "Runtime Error: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "Invalid Argument: " << e.what() << endl;
    } catch (...) {
        cout << "An unknown error occurred!" << endl;
    }
    
    cout << "\nAttempting invalid input:" << endl;
    try {
        int number = getValidNumber("Enter a number: ");
        cout << "You entered: " << number << endl;
    } catch (const runtime_error& e) {
        cout << "Runtime Error: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "Invalid Argument: " << e.what() << endl;
    } catch (...) {
        cout << "An unknown error occurred!" << endl;
    }
    
    return 0;
}