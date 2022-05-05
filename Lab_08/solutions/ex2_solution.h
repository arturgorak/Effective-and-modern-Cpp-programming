//
// Created by artem on 03.05.22.
//

#ifndef LAB8_EX2_SOLUTION_H
#define LAB8_EX2_SOLUTION_H


template<typename T>
class vector_traits{
    typedef T Type;
    typedef Type ScalarType;
    typedef const Type& ResultType;
    typedef const Type& ParamType;

    static Type mult(ScalarType scalarType, ParamType type) {
        return scalarType * type;
    }

    static Type default_value() {
        return Type{};
    }
};


template<>
class vector_traits<int> {
public:
    typedef int Type;
    typedef Type ScalarType;
    typedef Type ParamType;
    typedef Type ResultType;

    static Type mult(ScalarType scalarType, ParamType type) {
        return scalarType * type;
    }

    static Type default_value() {
        return 0;
    }
};

template<>
class vector_traits<double> {
public:
    typedef double Type;
    typedef Type ScalarType;
    typedef Type ParamType;
    typedef Type ResultType;

    static Type mult(ScalarType scalarType, ParamType type) {
        return scalarType * type;
    }

    static Type default_value() {
        return 0;
    }
};

template<>
class vector_traits<std::string> {
public:
    typedef std::string Type;
    typedef int ScalarType;
    typedef const Type& ParamType;
    typedef const Type& ResultType;

    static Type mult(ScalarType scalarType, ParamType type) {
        std::string result = "";
        for (int i = 0; i < scalarType; ++i) {
            result += type;
        }
        return result;
    }

    static Type default_value() {
        return "0";
    }
};

#endif //LAB8_EX2_SOLUTION_H
