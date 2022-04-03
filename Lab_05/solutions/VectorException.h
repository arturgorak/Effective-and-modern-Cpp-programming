//
// Created by artem on 03.04.2022.
//

#ifndef INC_05_VECTOREXCEPTION_H
#define INC_05_VECTOREXCEPTION_H

#endif //INC_05_VECTOREXCEPTION_H

#include <stdexcept>

class VectorException : public std::runtime_error {
public:
    VectorException(const std::string& string) : runtime_error(string) {}

    const char* what() const noexcept override {
        return runtime_error::what();
    }
};
