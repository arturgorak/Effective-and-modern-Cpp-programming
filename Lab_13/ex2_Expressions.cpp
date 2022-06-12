
#include <type_traits>
#include <iostream>
#include <iomanip>
#include "solutions/ex2.h"



using namespace std;
int main() {

    double a[] = {1, 2, 3};
    double b[] = {1, 1, 1};
    std::cout<< ScalarProduct<3>(a, b); // 6

    double x[] = {1, 1, 0};
    double A[] = {1, 0, 0,
                  2, -5, 1};
    cout << endl;
    double y[2];
    Multiply<2,3>(A, x, y);
    std::cout << y[0] << " " << y[1];  // 1 -3
}
