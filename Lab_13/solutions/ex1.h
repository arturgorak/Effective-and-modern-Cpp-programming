//
// Created by artem on 12.06.22.
//

#ifndef INC_13_EX1_H
#define INC_13_EX1_H

#include <iostream>
#include <type_traits>

template<int num, int pow>
struct Power {
    static const int value = num * Power<num, pow - 1>::value;
};

template<int num>
struct Power<num, 1> {
    static const int value = num;
};

template<int N, int K>
struct Binomial {
    static constexpr long long value = Binomial<N - 1, K>::value + Binomial<N - 1, K - 1>::value;
};

template<int N>
struct Binomial<N, N> {
    static constexpr long long value = 1;
};

template<>
struct Binomial<0, 0> {
    static constexpr long long value = 1;
};

template<int N>
struct Binomial<N, 0> {
    static constexpr long long value = 1;
};


#endif //INC_13_EX1_H
