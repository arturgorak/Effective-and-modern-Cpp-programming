//
// Created by artem on 08.04.2022.
//
#ifndef INC_06_EX1_SOLUTION_H
#define INC_06_EX1_SOLUTION_H

#endif //INC_06_EX1_SOLUTION_H

template<typename ...Args>
double average(Args... args){
    return (args + ... ) / double{sizeof...(args)};
}

template<typename Function, typename... Values>
auto computeSum(Function function, Values... values){
    return (function(values) + ...);
}

template <typename Container, typename ... Ts>
void insert(Container& container, Ts... args){
    (container.push_back(args), ...);
}