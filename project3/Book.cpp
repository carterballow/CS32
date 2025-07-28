#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book(std::string name, double price, std::string author)
    : Product(name, price), m_author(author) {}

std::string Book::getCategory() const {
    // TODO: Return "Book"
    return "";
}

bool Book::matchesKeyword(const std::string& keyword) const {
    // TODO: Return true if keyword is in name or author
    return false;
}

void Book::printInfo() const {
    // TODO: Print formatted output
}
