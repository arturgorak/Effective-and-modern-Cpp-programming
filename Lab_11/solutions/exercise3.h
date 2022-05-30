//
// Created by artem on 28.05.22.
//

#ifndef INC_11_EXERCISE2_H
#define INC_11_EXERCISE2_H

#include <algorithm>
#include "exercise1.h"

template<typename Container>
double median_inner(Container c, std::random_access_iterator_tag) {
    std::sort(c.begin(), c.end());
    int size = c.size();

    if (size % 2 != 0) {
        return c[(size - 1) / 2];
    } else {
        return (c[(size - 1) / 2] + c[size / 2]) / 2.0;
    }
}

template<typename Container>
double median_inner(Container c, std::forward_iterator_tag) {
    c.sort();
    int size = c.size();

    auto pointer = std::next(std::begin(c), (size - 1) / 2);
    auto val = *pointer;

    if (size % 2 != 0) {
        return val;
    } else {
        pointer = std::next(pointer);
        return (val + *pointer) / 2;
    }
}


template<typename Container>
double median(Container c) {
    return median_inner(c, typename std::iterator_traits<decltype(std::declval<Container>().begin())>::iterator_category());
}


#endif //INC_11_EXERCISE2_H
