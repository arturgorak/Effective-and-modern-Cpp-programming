//
// Created by artem on 03.03.2022.
//

#include <algorithm>
#include <iostream>
#include "Matrix.h"

Matrix::Matrix(unsigned int N, unsigned int M): N(N), M(M) {
//    this->N = N;
//    this->M = M;
    data = new double[N * M];
    std::fill(data, data + N * M, 0);
    std::cout << "  constructor of " << N << "x" << M << " matrix\n";
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> initializerList) {
    unsigned int max_size = 0;
    for (auto x: initializerList) {
        if (x.size() > max_size) {
            max_size = x.size();
        }
    }

    N = initializerList.size();
    M = max_size;
    data = new double[N * M];

    int index = 0;
    for (auto i: initializerList) {
        for (double j: i) {
            data[index] = j;
            index++;
        }
        for (int j = 0; j < M - i.size(); j++) {
            data[index] = 0;
            index++;
        }
    }
    std::cout << "  constructor of " << N << "x" << M << " matrix from initializer_list\n";
}

Matrix::Matrix(const Matrix &m) {
    this->N = m.N;
    this->M = m.M;
    this->data = new double[this->M * this->N];
    std::copy(m.data, m.data + this->M * this->N, this->data);
    std::cout << "  copy constructor\n";
}

Matrix &Matrix::operator=(const Matrix &m) {
    std::cout << "  copy assignment operator" << std::endl;
    if (this != &m) {
        this->N = m.N;
        this->M = m.M;

        delete[] this->data;
        this->data = nullptr;
        this->data = new double[m.M * m.N];
        std::copy(m.data, m.data + this->N * this->M, this->data);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Matrix &m) {
    double *p = m.data;
    for (int i = 0; i < m.N; i++) {
        stream << "{";
        for (int j = 0; j < m.M; j++) {
            stream << *p++;
            if (j != m.N) {
                stream << ", ";
            } else {
                stream << "}";
            }
        }
        stream << std::endl;
    }
    return stream;
}

double &Matrix::operator()(int x, int y) {
    return this->data[(x - 1) * this->M + (y - 1)];
}

Matrix::~Matrix() {
    delete[] this->data;
}

////--------------------------------exercise 2-------------------------------

Matrix Matrix::operator-() {
    Matrix res(N, M);
    for (int i = 0; i < this->M * this->N; i++) {
        res.data[i] = (-1) * data[i];
    }
    return res;
}

Matrix::Matrix(Matrix &&m) noexcept {
    this->N = m.N;
    this->M = m.M;

    this->data = m.data;
    std::cout << "  move constructor" << std::endl;
    m.data = nullptr;
}

Matrix& Matrix::operator=(Matrix&& m) noexcept {
    if (this != &m) {
        delete[] data;
        data = m.data;
        M = m.M;
        N = m.N;

        m.data = nullptr;
        m.M = 0;
        m.N = 0;
    }
    std::cout << "  move assignment operator" << std::endl;
    return *this;
}
