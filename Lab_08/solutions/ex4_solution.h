//
// Created by artem on 09.05.22.
//

#ifndef LAB8_EX4_SOLUTION_H
#define LAB8_EX4_SOLUTION_H

#include <iostream>
using namespace std;

template <int N>
class Vector {
    int data[N];
public:
    Vector() {
        cout << " Default constr" << endl;
    }

    Vector(std::initializer_list<int> list) {
        cout << " Init list constr" << endl;
        auto it = list.begin();
        for (int i = 0; i < N; i++) {
            data[i] = *it++;
        }
    }

    Vector(const Vector &m) {
        std::copy(m.data, m.data + N, data);
        cout << " Copy constr" << endl;
    }

    int operator[](int index) const {
        return data[index];
    }

    int &operator[](int index) {
        return data[index];
    }

    friend ostream &operator<<(ostream &out, const Vector &m) {
        for (auto x: m.data) {
            cout << x << ", ";
        }
        return out;
    }
};

template<class Left, class Right>
class VectorSum{
    const Left& left;
    const Right& right;

public:
    VectorSum(Left&& left, Right&& right): left(left), right(right) {}

    int operator[](int i) const {
        return left[i] + right[i];
    }

    template <int N>
    operator Vector<N>() const{
        Vector<N> v;
        for( int i=0; i<N; i++){
            v[i] = (*this)[i];
        }
        return v;
    }
};

template<class Left, class Right>
class VectorDiff{
    const Left& left;
    const Right& right;

public:
    VectorDiff(Left&& left, Right&& right): left(left), right(right) {}

    int operator[](int i) const {
        return left[i] - right[i];
    }

    template <int N>
    operator Vector<N>() const{
        Vector<N> v;
        for( int i=0; i<N; i++){
            v[i] = (*this)[i];
        }
        return v;
    }
};

template <class Left, class Right>
class VectorMult{
    const Left& left;
    const Right& right;

public:
    VectorMult(Left&& left, Right&& right) : left(left), right(right){}

    int operator[](int i) const {
        return left * right[i];
    }


    template <int N>
    explicit operator Vector<N>() const{
        Vector<N> v;
        for( int i=0; i<N; i++){
            v[i] = (*this)[i];
        }
        return v;
    }
};

template <typename L, typename R>
VectorSum<L,R> operator+(L&& l, R&& r){
    return {std::forward<L>(l), std:: forward<R> (r)};
}

template <typename L, typename R>
VectorMult<L,R> operator*(L&& l, R&& r){
    return {std::forward<L>(l), std:: forward<R> (r)};
}

template <typename L, typename R>
VectorDiff<L,R> operator-(L&& l, R&& r){
    return {std::forward<L>(l), std:: forward<R> (r)};
}
#endif //LAB8_EX4_SOLUTION_H
