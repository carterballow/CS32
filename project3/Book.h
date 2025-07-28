#ifndef BOOK_H
#define BOOK_H

#include "Product.h"

class Book : public Product {
public:
    Book(std::string name, double price, std::string author);
    virtual std::string getCategory() const;
    virtual bool matchesKeyword(const std::string& keyword) const;
    virtual void printInfo() const;

private:
    std::string m_author;
};

#endif
