//
// Created by artem on 28.05.22.
//

#ifndef INC_11_EXERCISE2_H
#define INC_11_EXERCISE2_H

#include "exercise1.h"


namespace v1 {
    template<typename T>
    typename std::enable_if_t<(hasSize<T>::value && hasValueType<T>::value), std::size_t>
    getSize(const T& x) {
        return x.size() * sizeof(typename T::value_type);
    }


    template<typename T>
    typename std::enable_if_t<!(hasSize<T>::value && hasValueType<T>::value), std::size_t>
    getSize(const T& x) {
        return sizeof(x);
    }
}

namespace v2 {
    template<typename T>
    auto getSize(const T& x) {
        if constexpr (hasSize<T>::value && hasValueType<T>::value) {
            return x.size() * sizeof(typename T::value_type);
        } else {
            return sizeof(x);
        }
    }
}


#endif //INC_11_EXERCISE2_H
