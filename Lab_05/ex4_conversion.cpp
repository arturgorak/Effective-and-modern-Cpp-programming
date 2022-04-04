#include <iostream>
#include <iomanip>
using namespace std;
#include "solutions/dynamicVector.h"


template <int N>
using SWektor = Vector<double, N>;
using DWektor = Vector<double, 0>;

int main(){
    cout <<fixed << setprecision(2);

	DWektor m1 = {1,  2,  3};    // dynamic z initialization_list
	cout << m1 << endl;

	SWektor<3> m2 = {1, -1, 0};  // static
    cout << m2 << endl;

    auto m3 = (SWektor<3>)(m1);  // conversion from dynamic to static
    cout << m3 << endl;

//    auto m6 = (DWektor)(m2); // my test to check conversion from static to dynamic
//    cout << m6 << endl;

    auto m4 = m1 + m2 + m1;
    cout << m4 << endl;


    auto m5 = static_cast<DWektor>(m4);
    cout << m5 << endl;

//    auto m7 = SWektor<5>(m2);
//    cout << m7 << endl;
//
//    auto m8 = SWektor<1>(m2);
//    cout << m8 << endl;
    return 0;
}
