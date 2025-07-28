#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Product.h"

class Electronics : public Product {
public:
    Electronics(std::string name, double price, int warrantyMonths);
    virtual std::string getCategory() const;
    virtual bool matchesKeyword(const std::string& keyword) const;
    virtual void printInfo() const;

private:
    int m_warrantyMonths;
};

#endif
