//
// Created by artem on 03.04.2022.
//
#include "staticVector.h"
#include <memory>


#ifndef INC_05_DYNAMICVECTOR_H
#define INC_05_DYNAMICVECTOR_H

#endif //INC_05_DYNAMICVECTOR_H

template<typename T>
class Vector<T, 0>{
private:
    int sizeOfArray = 0;
    std::unique_ptr<T[]> data;
public:
    Vector(int n) : data(std::make_unique<T[]>(n)) {

        sizeOfArray = n;
        std::fill(data.get(), data.get() + n, 0.0);
    };

    Vector(std::initializer_list<T> list) : data(std::make_unique<T[]>(list.size())){
        sizeOfArray = list.size();
        std::copy(list.begin(), list.end(), data.get());

    }

    Vector(const Vector& v) : data(std::make_unique<T[]>(v.sizeOfArray)) {
        sizeOfArray = v.sizeOfArray;
        std::copy(v.data.get(), v.data.get() + v.sizeOfArray, data.get());
    }

    Vector(Vector& v) : data(std::make_unique<T[]>(v.sizeOfArray)) {
        sizeOfArray = v.sizeOfArray;
        std::copy(v.data.get(), v.data.get() + v.sizeOfArray, data.get());
    }

    Vector& operator=(const Vector& v) {
        if (this == &v) {
            return *this;
        }

        if (v.sizeOfArray != sizeOfArray) {
            data = std::make_unique<T[]>(v.sizeOfArray);
            sizeOfArray = v.sizeOfArray;
        }
        std::copy(v.data.get(), v.data.get() + sizeOfArray, data.get());
        return *this;
    }


    int size() const{
        return sizeOfArray;
    }

    auto getData(){
        return data.get();
    }

    T operator[](int i) const {
        return data[i];
    }

    T& operator[](int i) {
        return data[i];
    }

    friend std::ostream &operator<<(std::ostream &stream, Vector<T,0> &v) {
        for (int i = 0; i < v.sizeOfArray; i++) {
            stream << v.data[i];
            if (i != v.sizeOfArray) {
                stream << " ";
            }
        }
        return stream;
    }

    friend std::ostream &operator<<(std::ostream &stream,const Vector<T,0> &v) {
        for (int i = 0; i < v.sizeOfArray; i++) {
            stream << v.data[i];
            if (i != v.sizeOfArray) {
                stream << " ";
            }
        }

        return stream;
    }

    typedef T value_type;

    void resize(int n){
        if(n > sizeOfArray){
            std::unique_ptr<T[]> tmp = std::make_unique<T[]>(n);
            std::copy(data.get(), data.get() + sizeOfArray, tmp.get());
            std::fill(tmp.get() + sizeOfArray, tmp.get() + n, 0.0);
            data = std::move(tmp);
            sizeOfArray = n;
        } else if(n < sizeOfArray){
            std::unique_ptr<T[]> tmp = std::make_unique<T[]>(n);
            std::copy(data.get(), data.get() + n, tmp.get());
            data = std::move(tmp);
            sizeOfArray = n;
        }
    }


    /// exercise 4
    template<typename S, int N>
    explicit operator Vector<S, N>() const {
        Vector<S,N> v{};
        if(N > sizeOfArray){
            for(int i = 0; i < sizeOfArray; i++){
                v[i] = static_cast<S>(data[i]);
            }
        } else{
            for(int i = 0; i < N; i++){
                v[i] = static_cast<S>(data[i]);
            }
        }
        //std::copy(data.get(), data.get() + N, v.getData());
        return v;
    }


};

template<typename T>
inline Vector<T, 0> operator+(Vector<T, 0> left,Vector<T, 0> right) {

    if ( left.size() != right.size() ) {
        throw VectorException("incompatible sizes in Vector::operator+");
    }
    Vector<T,0> res(left.size());
    for(int i = 0; i < left.size(); i++){
        res[i] = left[i] + right[i];
    }
    return res;
}







