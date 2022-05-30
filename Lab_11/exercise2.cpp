#include <iostream>
#include "solutions/exercise2.h"

using namespace std;

int main(){
    std::vector<int> v{1,2,3,4,5};
    cout << v1::getSize(5) << endl; // 4
    cout << v1::getSize(v) << endl; // 20
    cout << v2::getSize(5) << endl; // 4
    cout << v2::getSize(v) << endl; // 20
    return 0;
}