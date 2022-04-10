//
// Created by artem on 07.04.2022.
//
#include <cstdarg>
#include <vector>
#include <tuple>

#ifndef INC_06_PROXY_H
#define INC_06_PROXY_H

#endif //INC_06_PROXY_H


void showRecursive(int) {}

template <typename T, typename... Args>
void showRecursive(int i, T first, Args... args) {
    using boost::typeindex::type_id;
    std::cout << i << " > " << type_id<T>().pretty_name() << " [" << typeid(T).name() << "] = " << first << std::endl;

    showRecursive(i + 1, args...);
}


template<typename ...Types>
void showNames(Types&& ...Args) {
    showRecursive(1, std::forward<Types>(Args)...);
}


template<typename FUNCTOR>
class Proxy {
    FUNCTOR f;

public:
    Proxy(FUNCTOR&& f) : f(std::forward<FUNCTOR>(f)) {}

    template<typename ...Types>
    auto operator()(Types&& ...args) {
        showNames(std::forward<Types>(args)...);
        return f(std::forward<Types>(args)...);
    }
};

template<typename FUNCTOR> explicit Proxy(FUNCTOR&& f) -> Proxy<FUNCTOR>;

template<typename FUNCTOR>
Proxy<FUNCTOR> make_proxy(FUNCTOR&& f) {
    return Proxy<FUNCTOR>(std::forward<FUNCTOR>(f));
}