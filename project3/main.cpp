#include "Product.h"
#include "Clothing.h"
#include "Book.h"
#include "Electronics.h"

int main() {
    Product* p1 = new Clothing("Hoodie", 29.99, "M");
    Product* p2 = new Book("The AI Era", 12.50, "J. Doe");
    Product* p3 = new Electronics("Bluetooth Speaker", 59.99, 24);

    p1->printInfo();
    p2->printInfo();
    p3->printInfo();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
