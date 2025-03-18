#include <iostream>
#include <fstream>
#include <string>

class Student {
public:
    int rollNo;
    std::string name;
    std::string className;
    int year;
    double totalMarks;

    // Constructor
    Student(int rollNo = 0, std::string name = "", std::string className = "", int year = 0, double totalMarks = 0.0) {
        this->rollNo = rollNo;
        this->name = name;
        this->className = className;
        this->year = year;
        this->totalMarks = totalMarks;
    }

    // Function to display student details
    void display() {
        std::cout << "Roll No.: " << rollNo << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Class: " << className << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Total Marks: " << totalMarks << std::endl;
        std::cout << std::endl;
    }
};

// Function to write student records to a file
void writeRecordsToFile(Student students[], int size, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            file.write((char*)&students[i], sizeof(Student));
        }
        file.close();
        std::cout << "Records written to file successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

// Function to read student records from a file
void readRecordsFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        Student student;
        while (file.read((char*)&student, sizeof(Student))) {
            student.display();
        }
        file.close();
        std::cout << "Records read from file successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}

int main() {
    const std::string filename = "student_records.dat";
    const int numStudents = 5;

    Student students[numStudents] = {
        Student(1, "shivansh", "A", 2023, 85.0),
        Student(2, "lakshay", "B", 2022, 90.0),
        Student(3, "vishal", "A", 2023, 78.0),
        Student(4, "shashikant", "B", 2022, 92.0),
        Student(5, "raghuvendra", "A", 2023, 88.0)
    };

    writeRecordsToFile(students, numStudents, filename);
    std::cout << "Records in the file:" << std::endl;
    readRecordsFromFile(filename);

    return 0;
}
