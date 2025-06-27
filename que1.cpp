#include <iostream>
#include <string>

// Student class definition
class Student {
private:
    std::string name;
    int rollNumber;
    double subject1, subject2, subject3;
    
public:
    // Method to input student details
    void inputDetails() {
        std::cout << "Enter student name: ";
        std::getline(std::cin, name);
        
        std::cout << "Enter roll number: ";
        std::cin >> rollNumber;
        std::cin.ignore();  // Ignore newline left in input buffer
        
        std::cout << "Enter marks for Subject 1: ";
        std::cin >> subject1;
        std::cout << "Enter marks for Subject 2: ";
        std::cin >> subject2;
        std::cout << "Enter marks for Subject 3: ";
        std::cin >> subject3;
        std::cin.ignore();  // Ignore newline left in input buffer
    }
    
    // Method to calculate average marks
    double calculateAverage() {
        return (subject1 + subject2 + subject3) / 3;
    }
    
    // Method to display student information
    void displayInfo() {
        std::cout << "\nStudent Information:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Roll Number: " << rollNumber << std::endl;
        std::cout << "Subject 1 Marks: " << subject1 << std::endl;
        std::cout << "Subject 2 Marks: " << subject2 << std::endl;
        std::cout << "Subject 3 Marks: " << subject3 << std::endl;
        std::cout << "Average Marks: " << calculateAverage() << std::endl;
    }
};

int main() {
    Student student;
    
    std::cout << "Enter Student Details:" << std::endl;
    student.inputDetails();
    
    student.displayInfo();
    
    return 0;
}