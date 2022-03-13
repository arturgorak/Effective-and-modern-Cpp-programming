#include <iostream>
#include <algorithm>
#include <memory>
#include "MyString.h"
using namespace std;

class String{
   using string = emcpp::MyString;
//    using string = std::string;

/// Store a pointer to dynamically allocated string!

    shared_ptr<string> myString;
public:
    String() : myString(make_shared<string>()){}   /// creates an empty string

    String(const char * str): myString(make_shared<string>(str)){}   /// copy C-string

    String(const String & a): myString(a.myString){
       // myString = a.myString;
    }; // no copy

    String operator=(const String & s){
       if (this != &s) {
           this->myString = s.myString;
       }
       return *this;
    }; /// no copy
    /// makes a copy of a string if it has more than one reference.

    void set(int index, char ch) {
        if (!myString.unique()) {
            //myString.reset(new string(*myString));
            myString.reset(new string(*myString));
        }

        (*this->myString)[index] = ch;
    }

//    /// no copy
    char get(int index) const{
        return (*this->myString)[index];
    };
//    /// creates a new string only if both strings are non empty
     friend String operator+(String a, String b);
     friend std::ostream & operator<< (std::ostream & out, String s);
    };

inline std::ostream& operator<<(std::ostream & out, String s){
    out << *s.myString;
    return out;
}

inline String operator+(String a, String b){
    if (!a.myString->empty() && !b.myString->empty()) {
        String s((*(a.myString) + *(b.myString)).c_str());
        return s;
    } else if (!a.myString->empty()) {
        const String& s(a);
        return s;
    }
    return b;
}
