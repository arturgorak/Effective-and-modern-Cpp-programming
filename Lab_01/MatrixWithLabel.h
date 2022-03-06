//
// Created by artem on 03.03.2022.
//
#include <utility>
#include <string>
#include "Matrix.h"

#ifndef INC_01_MATRIXWITHLABEL_H
#define INC_01_MATRIXWITHLABEL_H



class MatrixWithLabel : Matrix{
    std::string label = "A";
public:
    using Matrix::Matrix;

    MatrixWithLabel(std::string label, int numberOfRows, int numberOfColumns);

    MatrixWithLabel(std::string label, std::initializer_list<std::initializer_list<double>> initializerList);

    void setLabel(std::string label2);

    std::string getLabel();

    MatrixWithLabel(const MatrixWithLabel& m);

    MatrixWithLabel(MatrixWithLabel&& m) noexcept = default;

    MatrixWithLabel& operator=(MatrixWithLabel&& m) noexcept = default;
};




#endif //INC_01_MATRIXWITHLABEL_H
