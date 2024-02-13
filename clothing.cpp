#include "clothing.h"
#include "util.h"
#include <sstream>
#include <iomanip> 


Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand):
    Product(category, name, price, qty),
    size_(size),
    brand_(brand)
{

}

std::set<std::string> Clothing::keywords() const 
{
    std::set<std::string> keys;
    std::set<std::string> productNames = parseStringToWords(name_);
    std::set<std::string> productBrands = parseStringToWords(brand_);
 
    std::set<std::string>::iterator nameit;
    for(nameit = productNames.begin(); nameit != productNames.end(); ++nameit) {
        keys.insert(*nameit);
    }

    std::set<std::string>::iterator brandit;
    for(brandit = productBrands.begin(); brandit != productBrands.end(); ++brandit) {
        keys.insert(*brandit);
    }

    return keys;

}

std::string Clothing::displayString() const
{
    std::string display = name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n";
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_;
    display += ss.str();
    display += " left.";
    return display;

}

void Clothing::dump(std::ostream& os) const
{
    os << "clothing" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << "\n";
}