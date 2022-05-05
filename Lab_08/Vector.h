
#ifndef LAB8_VECTOR_H
#define LAB8_VECTOR_H

#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

#include "solutions/ex2_solution.h"
#include "solutions/ex3_solution.h"

template <typename T, size_t N, typename P = safePolicy>
class Vector {
  T data[N];
 public:
  typedef T value_type;
  typedef std::size_t  size_type;
  typedef T* pointer;
  typedef T& reference;
  typedef const T& const_reference;

  typedef typename vector_traits<T>::Type ValueType;
  typedef typename vector_traits<T>::ParamType ParamType;
  typedef typename vector_traits<T>::ScalarType ScalarType;
  typedef typename vector_traits<T>::ResultType ReturnType;

  Vector() = default;
  Vector(const Vector & v) = default;
  Vector &operator=(const Vector & m) = default;

  Vector(const std::initializer_list<T> &list){
	std::copy(list.begin(), list.end(), data);
  }
  size_type size() const {
	return N;
  }

  ReturnType get(size_type index) const { /// ex2 const_reference -> ResultType
	return data[index];
  }

  void set(size_type index, const_reference value) {
	data[index] = value;
  }

  friend Vector operator* (ScalarType x, const Vector & v ){
	Vector result;
	for(int i=0; i < v.size(); ++i){
        /// ex 2 change
	  result.set(i, vector_traits<T>::mult(x, v.get(i)));
	}
	return result;
  }


  friend std::ostream &operator<<(std::ostream &out, const Vector & v) {
	for(int i=0; i < v.size(); ++i){
	  out << v.get(i) << " ";
	}
	return out;
  }

  friend std::istream &operator>>(std::istream &in, Vector & v) {
	Vector::value_type value;
	for(int i=0; i < v.size(); ++i){
	  in >> value;
	  if(in)
		v.set(i, value);
	}
	return in;
  }

};

#endif // LAB8_VECTOR_H