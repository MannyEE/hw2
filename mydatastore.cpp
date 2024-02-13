#include "mydatastore.h"
#include "util.h"

MyDataStore::MyDataStore(){}
MyDataStore::~MyDataStore()
{
    for(int i = 0; i < products.size(); i++) {
        delete products[i];
    }

    for(int i = 0; i < users.size(); i++) {
        delete users[i];
    }

}


void MyDataStore::addProduct(Product* p) 
{
    products.push_back(p);

    std::set<std::string> curkeywords = p->keywords();
    std::set<std::string>::iterator it = curkeywords.begin();

    for (; it != curkeywords.end(); ++it) {
        std::string lowstr = convToLower(*it);

        if (termToProduct.find(lowstr) == termToProduct.end()) {
            std::set<Product*> newterms;
            newterms.insert(p);
            termToProduct[lowstr] = newterms;
        } else {
            termToProduct[lowstr].insert(p);
        }
    }
}

void MyDataStore::addUser(User* u)
{
    users.push_back(u);
    std::vector<Product*> newuservec;
    userCarts[u] = newuservec;
}



std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{

    std::vector<Product*> matchingterms;
    //         if(termToProduct.find("men") != termToProduct.end()) {

    //             matchingterms.push_back(*(termToProduct["men"].begin()));
    //             return matchingterms;
    //         }



    if (type == 1) {
        for(int i = 0; i < terms.size(); i++) {

            if(termToProduct.find(terms[i]) != termToProduct.end()) {
                
                
                std::set<Product*> currterm = termToProduct[terms[i]];

                for(std::set<Product*>::iterator termit = currterm.begin();
                termit != currterm.end(); ++termit) 
                {
                    matchingterms.push_back(*termit);
                }
            }
        }


    } else {

        std::vector<std::set<Product*>> productlist;
        for(int i = 0; i < terms.size(); i++) {

            if (termToProduct.find(terms[i]) != termToProduct.end()) {
                productlist.push_back(termToProduct[terms[i]]);
            } else {
                return matchingterms;
            }
        }


        std::set<Product*> finalset;
        if(productlist.size() > 0) {
            finalset = productlist[0];
        } else {
            return matchingterms;
        }

        for(int i = 1; i < productlist.size(); i++) {
            finalset = setIntersection(finalset, productlist[i]);
        }


        for(std::set<Product*>::iterator it = finalset.begin(); it != finalset.end(); ++it) {
            matchingterms.push_back(*it);
        }

    }

    return matchingterms;
}

User* MyDataStore::getUser(std::string username)
{
    username = convToLower(username);
    std::map<User*, std::vector<Product*>>::iterator it = userCarts.begin();
    while(it != userCarts.end()) {
        if ((it->first)->getName() == username) {
            return it->first;
        }
        ++it;
    }

    return nullptr;
}

void MyDataStore::addToCart(User* u, Product* product)
{
    userCarts[u].push_back(product);
}


void MyDataStore::viewCart(User* u) 
{
    for(int i = 0; i < userCarts[u].size(); ++i) {
        std::cout << "Item " << i + 1 << "\n" << userCarts[u][i]->displayString() << '\n';
    }

}

void MyDataStore::buyCart(User* u)
{
    for(int i = 0; i < (userCarts[u]).size(); ++i) {
        if((userCarts[u][i]->getQty() > 0) && (userCarts[u][i]->getPrice() <= u->getBalance())){
            userCarts[u][i]->subtractQty(1);
            u->deductAmount(userCarts[u][i]->getPrice());
            userCarts[u].erase(userCarts[u].begin() + i);
            i--;
        }
    }
}

void MyDataStore::dump(std::ostream& ofile) 
{
    ofile << "<products>" << std::endl;
    for (int i = 0; i < products.size(); i++)
    {
        products[i]->dump(ofile);
    }
    ofile << "</products>" << std::endl;


    ofile << "<users>" << std::endl;
    for (unsigned int i = 0; i < users.size(); i++)
    {
        users[i]->dump(ofile);
    }
    ofile << "</users>" << std::endl;

}


