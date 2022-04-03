//
// Created by artem on 02.04.2022.
//

#ifndef INC_05_STATICVECTOR_H
#define INC_05_STATICVECTOR_H

#endif //INC_05_STATICVECTOR_H
#include "VectorException.h"

template<typename T, int N>
class Vector{
private:
    T data[N];
public:
    Vector(){
        std::fill(data, data + N, 0);
    }

    Vector(std::initializer_list<T> initializerList) {
        int index = 0;
        for (auto i: initializerList) {
            data[index] = i;
            index++;
        }
    }

    Vector(const Vector& v) {
        std::copy(v.getData(), v.getData() + N, data);
    }

    T operator[](int x) const {
        return data[x];
    }

    T& operator[](int x) {
        return data[x];
    }

    T* getData() {
        return data;
    }

    const T* getData() const {
        return data;
    }

    int size() const {
        return N;
    }

    typedef T value_type;

    /// exercise 4
    template<typename S>
    explicit operator Vector<S, 0>() const {
        Vector<S,0> v(N);
        std::copy(data, data + N, v.getData());
        return v;
    }

    template<typename S, int M>
    explicit operator Vector<S, 0>() const {
        std::cout << "sadasd"<< std::endl;
        Vector<S, M> v{};
        auto tmp = v.getData();
       // std::copy(data, data + N, v.getData());
        for(int i = 0 ; i< M; i++){
            tmp[i] = static_cast<S>(data[i]);
        }
        return v;
    }

};


template<typename T, int N>
std::ostream &operator<<(std::ostream &stream, Vector<T,N> &v) {
    double *p = v.getData();
        for (int i = 0; i < N; i++) {
            stream << *p++;
            if (i != N) {
                stream << " ";
            }
        }
    return stream;
}

template<typename T, int N>
inline Vector<T, N> operator+(Vector<T, N> left, Vector<T, N> right) {
    for(int i = 0; i < N; i++){
        left[i] += right[i];
    }
    return left;
}

///exercise 4
template<typename T, int N>
inline Vector<T, N> operator+(Vector<T, N> left, Vector<T, 0>& right) {
    if ( left.size() != right.size() ) {
        throw VectorException("incompatible sizes in Vector::operator+");
    }
    for(int i = 0; i < left.size(); i++){
        left[i] += right[i];
    }
    return left;
}

template<typename T, int N>
inline Vector<T, N> operator+(Vector<T, 0> left, Vector<T, N>& right) {
    if ( left.size() != right.size() ) {
        throw VectorException("incompatible sizes in Vector::operator+");
    }
    for(int i = 0; i < left.size(); i++){
        right[i] += left[i];
    }
    return right;
}



