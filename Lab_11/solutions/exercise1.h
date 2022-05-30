//
// Created by artem on 28.05.22.
//

#ifndef INC_11_EXERCISE1_H
#define INC_11_EXERCISE1_H
#include <iostream>
#include <vector>
#include <type_traits>

template<typename... Ts>
using void_t = void;

template<typename T, typename = void>
struct hasSize : std::false_type {};

template<typename T>
struct hasSize<T, std::void_t<decltype(&T::size)>> : std::true_type {
};

//template<typename T>
//struct hasSize<T, std::void_t<typename T::size>> : std::true_type {
//};

template<typename T, typename = void>
struct hasValueType : std::false_type {};

template<typename T>
struct hasValueType<T, std::void_t<typename T::value_type>> : std::true_type {
};


#endif //INC_11_EXERCISE1_H
