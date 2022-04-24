//#pragma include once

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

template <typename T, size_t N, size_t M>
class Matrix{

	T data[N*M];

 public:
    constexpr size_t numberOfRows() const { return N; } // add constexpr and const
    constexpr size_t numberOfColumns() const { return M; } // add constexpr and const

	
	Matrix(size_t nrows=N, size_t ncols=M){
	  std::fill_n(data, nrows*ncols, T{});
	}


    Matrix(const std::initializer_list<std::initializer_list<T>> & list){
		T * p = data;
		for(const auto & row: list){
	  		T* p2 = std::copy(row.begin(), row.end(), p);
	  		std::fill(p2, p+=M, T{});
		}
    }

	Matrix(const Matrix & m){
		std::copy_n(m.data, N*M, data);
	}
	
	Matrix & operator= (const Matrix & m){
		if(&m != this){
			std::copy_n(m.data, N*M, data);
		}
		return *this;
	}

    T& operator()(int i, int j){
	   return data[(i-1)*M+j-1] ;
	}

    T operator()(int i, int j)  const{ // new operator with const
        return data[(i-1)*M+j-1] ;
    }

    friend Matrix operator+(const Matrix & a,const Matrix &b) { // adding consts
        Matrix r;
        for(size_t i = 1; i <= N; ++i){ // int to size_t
            for(size_t j = 1; j <= M; ++j){ // int to size_t
                r(i,j) = a(i,j) + b(i,j) ;
            }
        }
        return r;
    }
    ///----------------------------------------------------------------------------------------------
    /// exercise 3


    class Iterator{
        T* iterator;
        std::size_t step;

    public:
        explicit Iterator(T* iterator, size_t step = 1) : iterator(iterator), step(step) {}

        explicit Iterator(const T* iterator, size_t step = 1) : iterator((T *) iterator), step(step) {}

        Iterator& operator++() {
            iterator += step;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        T& operator*() {
            return *iterator;
        }

        const T& operator*() const {
            return *iterator;
        }

        friend inline bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.iterator == rhs.iterator; }

        friend inline bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !operator==(lhs, rhs); }

        friend inline bool operator<(const Iterator& lhs, const Iterator& rhs) { return lhs.iterator < rhs.iterator; }

        friend inline bool operator>(const Iterator& lhs, const Iterator& rhs) { return operator<(rhs, lhs); }

        friend inline bool operator<=(const Iterator& lhs, const Iterator& rhs) { return !operator>(lhs, rhs); }

        friend inline bool operator>=(const Iterator& lhs, const Iterator& rhs) { return !operator<(lhs, rhs); }


        T* operator->() {
            return iterator;
        }

        const T* operator->() const {
            return iterator;
        }

    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator begin() const{
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + N * M);
    }

    Iterator end() const{
        return Iterator(data + N * M);
    }

    Iterator row_begin(int n) {
        return Iterator(data + (n - 1) * M);
    }

    Iterator row_end(int n) {
        return Iterator(data + n * M);
    }

    Iterator col_begin(int n) {
        return Iterator(data + (n - 1), M);
    }

    Iterator col_end(int n) {
        return Iterator(data + N * M + (n - 1));
    }

    ////---
    using row_iterator = Iterator;
    using col_iterator = Iterator;

   

};

template <typename T, size_t N, size_t M>
void printMatrix(const Matrix<T,N,M> & m, int width = 10){
	for(int i = 1; i <= static_cast<int>(m.numberOfRows()); ++i){ // cast size_t to int

		for(int j = 1; j <= static_cast<int>(m.numberOfColumns()); ++j){ // cast size_t to int
			if(j != 1)
				cout << " ";

			cout << setw(width) <<  m(i,j) ;
		}
		cout << endl;
	}
}

///------------------------------------------------------------------------------
///exercise 3

template<typename T, int N, int M>
inline Matrix<T, N, M> operator+(Matrix<T, N, M> lhs, const Matrix<T, N, M>& rhs) {
    lhs += rhs;
    return lhs;


}


