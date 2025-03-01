#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "address.h"
#include "date.h"

class Student {
private:
    std::string firstName;
    std::string lastName;
    Address address;
    Date birthDate;
    Date gradDate;
    int creditHours;

public:
    Student();
    void init(std::string studentData);
    void printStudent() const;
    std::string getLastFirst() const;
    std::string getFirstName() const;
    int getCreditHours() const;
};

#endif
