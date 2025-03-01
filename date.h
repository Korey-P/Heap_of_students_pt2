#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    void init(std::string dateStr);
    void printDate() const;
};

#endif
