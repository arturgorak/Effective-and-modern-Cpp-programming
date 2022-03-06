//
// Created by artem on 03.03.2022.
//

#include "MatrixWithLabel.h"

#include <utility>
#include <iostream>

void MatrixWithLabel::setLabel(std::string label2) {
    this->label = std::move(label2);
}

MatrixWithLabel::MatrixWithLabel(std::string label, int numberOfRows, int numberOfColumns) : Matrix(numberOfRows,numberOfColumns), label(std::move(label)){}

MatrixWithLabel::MatrixWithLabel(std::string label, std::initializer_list<std::initializer_list<double>> initializerList) : Matrix(initializerList), label(std::move(label)){}

std::string MatrixWithLabel::getLabel(){
    return this->label;
}

MatrixWithLabel::MatrixWithLabel(const MatrixWithLabel& m) : Matrix(m), label(m.label) {
    std::cout << "  label copy constructor" << std::endl;
}