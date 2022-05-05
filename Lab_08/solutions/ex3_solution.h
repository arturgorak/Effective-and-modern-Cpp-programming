//
// Created by artem on 03.05.22.
//

#ifndef LAB8_EX3_SOLUTION_H
#define LAB8_EX3_SOLUTION_H

#ifndef MEC_VECTORPOLICIES_H
#define MEC_VECTORPOLICIES_H

#include <algorithm>
#include <iostream>

#include "ex2_solution.h"

class safePolicy {
public:
    template<typename T>
    static void init(T* data, int N) {
        std::fill(data, data + N, vector_traits<T>::default_value());
    }

    template<typename T>
    static void init(T* data, const std::initializer_list<T>& list, int N) {
        if (list.size() <= N and N >= 0) {
            std::copy(list.begin(), list.end(), data);
        } else {
            throw std::exception();
        }
    }

    static void check(int index, int N) {
        if (index < 0 or N <= index) {
            throw std::exception();
        }
    }
};

class fastPolicy {
public:
    template<typename T>
    static void init(T& data, int N) {}

    template<typename T>
    static void init(T* data, const std::initializer_list<T>& list, int N) {
        std::copy(list.begin(), list.begin() + N, data);
    }

    static void check(int index, int N) {}
};

class InitFastPolicy {
public:
    template<typename T>
    static void init(T* data, int N) {
        std::fill(data, data + N, vector_traits<T>::default_value());
    }

    template<typename T>
    static void init(T* data, const std::initializer_list<T>& list, int N) {
        std::copy(list.begin(), list.begin() + N, data);
    }

    static void check(int index, int N) {}
};

#endif //MEC_VECTORPOLICIES_H

#endif //LAB8_EX3_SOLUTION_H
