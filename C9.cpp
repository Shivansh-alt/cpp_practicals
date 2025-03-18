#include <iostream>
#include <string>

class Person {
public:
    std::string name;

    Person(std::string n) : name(n) {}

    virtual void display() {
        std::cout << "Name: " << name << std::endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
public:
    std::string course;
    double marks;
    int year;

    Student(std::string n, std::string c, double m, int y) 
        : Person(n), course(c), marks(m), year(y) {}

    void display() override {
        Person::display();
        std::cout << "Course: " << course << std::endl;
        std::cout << "Marks: " << marks << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

class Employee : public Person {
public:
    std::string department;
    double salary;

    Employee(std::string n, std::string d, double s) 
        : Person(n), department(d), salary(s) {}

    void display() override {
        Person::display();
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: " << salary << std::endl;
    }
};

int main() {
    Person* p1 = new Student("shivansh pandey", "CS", 85.0, 3);
    Person* p2 = new Employee("Vishal sharma", "CEO", 500000.0);

    p1->display();
    std::cout << std::endl;
    p2->display();

    delete p1;
    delete p2;

    return 0;
}
