#include <iostream>
#include "Matrix.h"
#include "MatrixWithLabel.h"

using namespace std;

 int main() {
    Matrix m1; // default constructor: N=M=0, data=nullptr
    Matrix m2(3,4); // N = 3, M = 4, data = N*M doubles set to 0.0
    Matrix m3({{1,2,3},{32, 23, 22},{3,234,23,44}}); // from initializer_list
    cout << m2(1,1) << endl; // 0 - the first element in data (we count from 1)
    cout << m3(2,2) << endl; // 23
    cout << m3; // prints matrix
    cout << "Copy semantics \n";
    Matrix m4 = m2; // copy constructor that makes deep copy of the matrix m2
    m4 = m3; // copy assignment makes deep copy of the matrix m3
    cout << "----------------------------------" << endl;
    cout << "Move semantics \n";
    Matrix m7 = std::move(m2);
    m4 = -m3;
    cout << "Copy elision \n";
    Matrix m6 = -m4;
    Matrix * pm = new Matrix(-m4);
    cout << m6(2,1) << endl; // 32
    cout << "-----------------------------------\n";
    cout << "Inheritance \n";
    MatrixWithLabel l0("B", 3, 4);
    MatrixWithLabel l1({{1,2},{4,5}});
    l1.setLabel("A");
    MatrixWithLabel l2 = l1;
    MatrixWithLabel l3 = std::move(l1);
    cout << l2.getLabel() << " " << l3.getLabel() << endl;
    cout << l1.getLabel() << endl;
    delete pm;
    

    return 0;
}
