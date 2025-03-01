#include "date.h"
#include <sstream>

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

void Date::init(std::string dateStr) {
    char slash;
    std::stringstream ss(dateStr);
    ss >> month >> slash >> day >> slash >> year;
}

void Date::printDate() const {
    std::cout << month << "/" << day << "/" << year << std::endl;
}
