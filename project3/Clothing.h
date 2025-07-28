#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"

class Clothing : public Product {
public:
    Clothing(std::string name, double price, std::string size);
    virtual std::string getCategory() const;
    virtual bool matchesKeyword(const std::string& keyword) const;
    virtual void printInfo() const;

private:
    std::string m_size;
};

#endif
