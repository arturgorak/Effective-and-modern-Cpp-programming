//
// Created by artem on 21.05.22.
//

#ifndef INC_10_EX1_SOLUTION_H
#define INC_10_EX1_SOLUTION_H

double operator "" _ms(long double x){
    return x / 1000;
}

double operator "" _ms(unsigned long long x){
    return (static_cast<double>(x)) / 1000;
}

double operator "" _s(long double x){
    return x;
}

double operator "" _s(unsigned long long x){
    return (static_cast<double>(x));
}

double operator "" _h(long double x){
    return x * 3600;
}

double operator "" _h(unsigned long long x){
    return (static_cast<double>(x)) * 3600;
}

double operator "" _km(long double x){
    return x * 1000;
}

double operator "" _km(unsigned long long x){
    return (static_cast<double>(x)) * 1000;
}

double operator "" _m(long double x){
    return x;
}

double operator "" _m(unsigned long long x){
    return (static_cast<double>(x));
}

double operator "" _cm(long double x){
    return x / 100;
}

double operator "" _cm(unsigned long long x){
    return (static_cast<double>(x)) / 100;
}
#endif //INC_10_EX1_SOLUTION_H
