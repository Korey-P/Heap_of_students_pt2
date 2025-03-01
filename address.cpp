#include "address.h"

Address::Address() {
    street = "";
    city = "";
    state = "";
    zip = "";
}

void Address::init(std::string s, std::string c, std::string st, std::string z) {
    street = s;
    city = c;
    state = st;
    zip = z;
}

void Address::printAddress() const {
    std::cout << street << std::endl;
    std::cout << city << " " << state << ", " << zip << std::endl;
}
