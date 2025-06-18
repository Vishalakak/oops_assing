#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
private:
    string name;
    int age;
    
public:
    // Default constructor
    Person() {
        cout << "Person default constructor called" << endl;
        name = "";
        age = 0;
    }
    
    // Parameterized constructor
    Person(string n, int a) {
        cout << "Person parameterized constructor called" << endl;
        name = n;
        age = a;
    }
    
    // Display method
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class Employee
class Employee : public Person {
private:
    string employeeID;
    double salary;
    
public:
    // Default constructor
    Employee() {
        cout << "Employee default constructor called" << endl;
        employeeID = "";
        salary = 0.0;
    }
    
    // Parameterized constructor
    Employee(string n, int a, string id, double s) 
        : Person(n, a) {  // Calling base class constructor
        cout << "Employee parameterized constructor called" << endl;
        employeeID = id;
        salary = s;
    }
    
    // Display method
    void display() {
        Person::display();  // Call base class display
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Create a Person object
    Person person("vishal", 20);
    cout << "\nPerson Details:" << endl;
    person.display();
    
    // Create an Employee object
    Employee employee("ankit", 21, "E001", 50000.0);
    cout << "\nEmployee Details:" << endl;
    employee.display();
    
    return 0;
}