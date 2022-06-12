#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cctype>
#include <ctime>
#include <thread>
#include <utility>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

template <int N>
struct Array{
    int a[N];
    int i = 0;
    long long sum = 0;
    mutex my_mutex;

    int f(int x){
        int y = x%11;
        return (y*y+1);
    }

    void generateArray(){
        while(true){
            lock_guard<mutex> lockGuard(my_mutex);
            if(i < N) {
                a[i++] = f(random());
            } else {
                break;
            }
        }
    }

    long long computeSum(){
        for(int x: a){
            lock_guard<mutex> lockGuard(my_mutex);
            sum += x;
        }
        return sum;
    }
};

int main(){
    srand(2019);
    using A = Array<1000>;
    A array;
    int thread_count = 10;
    vector<thread> threads;

    threads.reserve(thread_count);
    for(int i = 0; i < thread_count; i++) {
        threads.emplace_back(&A::generateArray, &array);
    }

    for (auto& t : threads) {
        t.join();
    }

    threads.clear();

    for(int i = 0; i < thread_count; i++) {
        threads.emplace_back(&A::computeSum, &array);
    }

    for (auto& t : threads) {
        t.join();
    }

    for(int i=0; i<40; i++){
        cout << array.a[0+i] << "  ";
    }
    long long sum = array.computeSum();
    cout << "\n sum = " << sum << endl;

}
