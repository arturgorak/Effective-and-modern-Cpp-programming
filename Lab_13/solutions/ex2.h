//
// Created by artem on 12.06.22.
//

#ifndef INC_13_EX2_H
#define INC_13_EX2_H


template<int N, typename T> //N is a size of vectors, T is type of its elements
constexpr T ScalarProduct(T* a, T* b) {
    if constexpr (N == 0) {
        return 0;
    } else {
        return a[N - 1] * b[N - 1] + ScalarProduct<N - 1>(a, b);
    }
};


template<int N, int M, typename T> // (N, M are sizes of a matrix, T is type of its elements)
constexpr void Multiply(T* A, T* x, T* y) {
    if constexpr (N != 0) {
        y[N - 1] = ScalarProduct<M>(x, A + (N - 1) * M);
        Multiply<N - 1, M>(A, x, y);
    }
}

#endif //INC_13_EX2_H
