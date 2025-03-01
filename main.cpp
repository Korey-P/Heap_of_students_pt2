#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(const std::vector<Student*>& students);
void showStudentNames(const std::vector<Student*>& students);
void findStudent(const std::vector<Student*>& students);
void deleteStudents(std::vector<Student*>& students);
std::string menu();
void sortStudents(std::vector<Student*>& students, int option);

int main() {
    std::vector<Student*> students;
    loadStudents(students);

    std::string choice;
    while (true) {
        choice = menu();
        
        if (choice == "0") {
            break;
        } else if (choice == "1") {
            showStudentNames(students);
        } else if (choice == "2") {
            printStudents(students);
        } else if (choice == "3") {
            findStudent(students);
        } else if (choice == "4") {
            std::cout << "Sort by: \n1) Last Name\n2) First Name\n3) Credit Hours (Descending)\nChoice: ";
            int sortOption;
            std::cin >> sortOption;
            sortStudents(students, sortOption);
            std::cout << "Students sorted successfully.\n";
        } else {
            std::cout << "Invalid option. Please choose again.\n";
        }
    }

    deleteStudents(students);
    std::cout << "Program exiting. Memory cleaned up.\n";
    return 0;
}

void loadStudents(std::vector<Student*>& students) {
    std::ifstream file("students.csv");
    if (!file) {
        std::cerr << "Error opening students.csv\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        Student* student = new Student();
        student->init(line);
        students.push_back(student);
    }
    file.close();
    std::cout << "Loaded " << students.size() << " students.\n";
}

void printStudents(const std::vector<Student*>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        students[i]->printStudent();
        std::cout << "____________________________________\n";
    }
}

void showStudentNames(const std::vector<Student*>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        std::cout << students[i]->getLastFirst() << std::endl;
    }
}

void findStudent(const std::vector<Student*>& students) {
    std::string lastName;
    std::cout << "Enter last name to search: ";
    std::cin >> lastName;

    bool found = false;
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getLastFirst().find(lastName) != std::string::npos) {
            students[i]->printStudent();
            std::cout << "____________________________________\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No student found with last name containing '" << lastName << "'.\n";
    }
}

void deleteStudents(std::vector<Student*>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        delete students[i];
    }
    students.clear();
}

std::string menu() {
    std::cout << "\n0) Quit\n";
    std::cout << "1) Print all student names\n";
    std::cout << "2) Print all student data\n";
    std::cout << "3) Find a student\n";
    std::cout << "4) Sort students\n";
    std::cout << "Please choose 0-4: ";
    
    std::string choice;
    std::cin >> choice;
    return choice;
}

void sortStudents(std::vector<Student*>& students, int option) {
    if (option == 1) { // Sort by last name
        for (size_t i = 0; i < students.size(); i++) {
            for (size_t j = i + 1; j < students.size(); j++) {
                if (students[i]->getLastFirst() > students[j]->getLastFirst()) {
                    Student* temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    } else if (option == 2) { // Sort by first name
        for (size_t i = 0; i < students.size(); i++) {
            for (size_t j = i + 1; j < students.size(); j++) {
                if (students[i]->getFirstName() > students[j]->getFirstName()) {
                    Student* temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    } else if (option == 3) { // Sort by credit hours (descending)
        for (size_t i = 0; i < students.size(); i++) {
            for (size_t j = i + 1; j < students.size(); j++) {
                if (students[i]->getCreditHours() < students[j]->getCreditHours()) {
                    Student* temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }
}
