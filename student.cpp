#include "student.h"
#include <sstream>

Student::Student() {
    firstName = "";
    lastName = "";
    creditHours = 0;
}

void Student::init(std::string studentData) {
    std::stringstream ss(studentData);
    std::string street, city, state, zip, birth, grad, credits;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, zip, ',');
    getline(ss, birth, ',');
    getline(ss, grad, ',');
    getline(ss, credits, ',');

    address.init(street, city, state, zip);
    birthDate.init(birth);
    gradDate.init(grad);
    creditHours = std::stoi(credits);
}

void Student::printStudent() const {
    std::cout << firstName << " " << lastName << std::endl;
    address.printAddress();
    std::cout << "DOB: ";
    birthDate.printDate();
    std::cout << "Grad: ";
    gradDate.printDate();
    std::cout << "Credits: " << creditHours << std::endl;
}

std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}

std::string Student::getFirstName() const {
    return firstName;
}

int Student::getCreditHours() const {
    return creditHours;
}
