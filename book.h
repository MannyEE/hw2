#ifndef PRODUCT_H
#define PRODUCT_H
#include "hw2/product.h"

class Book : public Product {
public:
    Book(const std::string category, const std::string name, double price, int qty,
    std::string isbn, std::string author);

    std::set<std::string> keywords();

    std::string displayString() const;

    void dump(std::ostream& os) const;



private:
    string isbn_;
    string author_;

};