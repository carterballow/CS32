#include "Clothing.h"
#include <iostream>
#include <iomanip>

Clothing::Clothing(std::string name, double price, std::string size)
    : Product(name, price), m_size(size) {}

std::string Clothing::getCategory() const {
    // TODO: Return "Clothing"
    return "";
}

bool Clothing::matchesKeyword(const std::string& keyword) const {
    // TODO: Return true if keyword is in name or size
    return false;
}

void Clothing::printInfo() const {
    // TODO: Print formatted output
}
