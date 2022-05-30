//
// Created by artem on 28.05.22.
//

#include "solutions/exercise1.h"

using namespace std;

int main(){
    cout << hasSize< int >::value << endl; // false
    cout << hasSize< vector<int> >::value << endl; //true
    auto tmp = vector<int>{};
    cout << hasValueType< int >::value << endl; // false
    cout << hasValueType< vector<int> >::value << endl; //true
    return 0;

}
