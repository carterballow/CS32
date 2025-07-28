#include "Electronics.h"
#include <iostream>
#include <iomanip>

Electronics::Electronics(std::string name, double price, int warrantyMonths)
    : Product(name, price), m_warrantyMonths(warrantyMonths) {}

std::string Electronics::getCategory() const {
    // TODO: Return "Electronics"
    return "";
}

bool Electronics::matchesKeyword(const std::string& keyword) const {
    // TODO: Return true if keyword is in name or matches warranty
    return false;
}

void Electronics::printInfo() const {
    // TODO: Print formatted output
}
