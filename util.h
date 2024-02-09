#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    typename std::set<T> intersection;
    typename std::set<T>::iterator it;

    for(it = s1.begin(); it != s1.end; it++) {
        if (s2.find(*it) != s2.end()) {
            intersection.insert(*it);
        }
    }





}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    typename std::set<T>::iterator s2it;
    typename std::set<T>::iterator s1it;
    typename std::set<T> unionset;

    for(s2it = s2.begin(), s1it = s1.begin(); s1it != s1.end || s2 != s2.end(); s1it++, s2it++) {
        unionset.insert(*s1it);
        unionset.insert(*s2it);
    }

    typename std::set<T>::iterator final;
    if (s1it == s1.end()) final = s2it;
    if (s2it == s2.end()) final = s1it;

    for(;final != s2.end() && final != s1.end(); final++) {
        unionset.insert(*final);
    }

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
