#pragma once
#include <iostream>
#include <memory>
#include "Box.h"

using namespace std;

class Container{
    // Exercise 2: Use smart pointer.
    // Box * pbox = nullptr;

    unique_ptr<Box> pbox;
public:
    static bool verbose;
    Container(int content): pbox(new Box(content)){
        if(verbose) cout << "Creating Container" << endl;
        //pbox->setContent(content);
    }
    Container(const Container & container): pbox(new Box{*(container.pbox)}){
        if(verbose) cout << "Creating copy of Container\n";
    }
    Container & operator=(const Container &container){
        if(verbose) cout << "Copying Container\n";
        if(this != &container) {
            *pbox = *container.pbox;
        }
        return *this;
    }

    ~Container(){
        if(verbose) cout << "Destroying Container \n";
    }

    friend Container operator+(const Container & p1, const Container & p2);
    friend std::ostream & operator << (std::ostream & out, const Container & p){
        return (out << " [" << p.pbox->getContent() << "] ");
    }

    //copy elision
    Container(Container && container) noexcept {
        if(verbose) cout << "Container: move constructor.\n";
        this->pbox = std::move(container.pbox);
    }

    Container & operator=(Container && container) noexcept {
        if(verbose) cout << "Container: move assignment.\n";
        if (&container != this) {
            this->pbox = std::move(container.pbox);
        }
        return *this;
    }
};

bool Container::verbose = false;

inline Container operator+(const Container & p1, const Container & p2){
    Container suma(p1.pbox->getContent() + p2.pbox->getContent());
    return suma;
}
