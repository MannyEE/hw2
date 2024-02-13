#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include "datastore.h"

class MyDataStore : public DataStore 
{
public:
    /**
     * Adds a product to the data store
     */
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    void viewCart(User* u);

    void addToCart(User* u, Product* product);

    void buyCart(User* u);

    User* getUser(std::string username);



private:
    std::vector<Product*> products;
    std::vector<User*> users;
    std::map<User*, std::vector<Product*>> userCarts;
    std::map<std::string, std::set<Product*>> termToProduct;


};
#endif