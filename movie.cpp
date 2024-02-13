#include "movie.h"
#include "util.h"
#include <iomanip> 
#include <sstream>


Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating):
    Product(category, name, price, qty),
    rating_(rating),
    genre_(genre)
{

}

std::set<std::string> Movie::keywords() const 
{
    std::set<std::string> keys;
    std::set<std::string> productNames = parseStringToWords(name_);
    // std::set<std::string> productgenres = parseStringToWords(genre_);

    keys.insert(genre_);

    std::set<std::string>::iterator nameit;
    for(nameit = productNames.begin(); nameit != productNames.end(); ++nameit) {
        keys.insert(*nameit);
    }

    // std::set<std::string>::iterator genreit;
    // for(genreit = productgenres.begin(); genreit != productgenres.end(); ++genreit) {
    //     keys.insert(*genreit);
    // }

    return keys;

}

std::string Movie::displayString() const
{

    std::string display = name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n";
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_;
    display += ss.str();
    display += " left.";
    return display;
}

void Movie::dump(std::ostream& os) const
{
    os << "movie" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_<< "\n" << rating_ << "\n";
}