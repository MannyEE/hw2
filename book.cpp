#include "book.h"
#include "util.h"
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <iomanip> 

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author):
    Product(category, name, price, qty),
    isbn_(isbn),
    author_(author)
{

}

std::set<std::string> Book::keywords() const 
{
    std::set<std::string> keys;
    std::set<std::string> productNames = parseStringToWords(name_);
    std::set<std::string> productAuthor = parseStringToWords(author_);
    
    keys.insert(isbn_);

    std::set<std::string>::iterator nameit;
    for(nameit = productNames.begin(); nameit != productNames.end(); ++nameit) {
        keys.insert(*nameit);
    }

    std::set<std::string>::iterator authorit;
    for(authorit = productAuthor.begin(); authorit != productAuthor.end(); ++authorit) {
        keys.insert(*authorit);
    }

    return keys;

}

std::string Book::displayString() const
{

    std::string display = name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n";
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_;
    display += ss.str();
    display += " left.";
    return display;
}

void Book::dump(std::ostream& os) const
{
    os << "book" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << "\n";
    
}