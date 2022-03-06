//
// Created by artem on 03.03.2022.
//

#ifndef INC_01_MATRIX_H
#define INC_01_MATRIX_H


class Matrix{
    unsigned int N = 0;
    unsigned int M = 0;
    double *data = nullptr;
public:
    Matrix()= default;

    Matrix(unsigned int N,unsigned int M);

    Matrix (std::initializer_list<std::initializer_list<double>> initializerList);

    Matrix(const Matrix& m);

    Matrix& operator=(const Matrix& m);

    friend std::ostream& operator<< (std::ostream& stream, const Matrix& m);

    double& operator()(int x, int y);

    double operator()(int x, int y) const{
        return this->data[(x - 1) * this->M + (y - 1)];
    }

    ~Matrix();
    ////--------------------------------exercise 2-------------------------------
    Matrix operator-();

    Matrix(Matrix&& m) noexcept;

    Matrix& operator=(Matrix&& m) noexcept;
};


#endif //INC_01_MATRIX_H
