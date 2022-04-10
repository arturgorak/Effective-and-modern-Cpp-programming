//
// Created by artem on 10.04.2022.
//

#ifndef INC_06_EX4_SOLUTION_H
#define INC_06_EX4_SOLUTION_H

#endif //INC_06_EX4_SOLUTION_H

#include <iostream>
#include <vector>

template<typename...Types>
class MultiVector{
public:
    void print(){
        std:: cout << std::endl;
    }
};

template<typename T, typename...Types>
class MultiVector<T, Types...>:MultiVector<Types...>{
    std::vector<T> data;
public:
    void push_back(T value){
        data.push_back(value);
    }

    template<class S>
    void push_back(S value){
        MultiVector<Types...>& multiVector = *this;
        multiVector.push_back(value);
    }

    void print(){
        std::cout << "[ ";
        for(const auto& x: data){
            std::cout << x << " ";
        }
        std::cout << "] ";
        MultiVector<Types ...> & multiVector = *this;
        multiVector.print();
    }
};
