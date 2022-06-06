//
// Created by artem on 06.06.22.
//
#include <iostream>
#include <future>
#include <fstream>
#include <vector>

#include "solutions/ex3.h"

using namespace std;

int main(int argc, char* argv[]){

    //Szablon klasy std::promise zapewnia możliwość przechowywania wartości lub wyjątku,
    // który jest później uzyskiwany asynchronicznie przez obiekt std::future utworzony przez obiekt std::promise.
    vector<future<long>> futures;
    vector<promise<long>> promises;
    vector<thread> threads;

    futures.reserve(argc - 1);
    promises.reserve(argc - 1);
    threads.reserve(argc - 1);

    for (int i = 0; i < argc - 1; i++) {
        promises.emplace_back();
        futures.push_back(promises.at(i).get_future());
        threads.emplace_back(func, &promises.at(i), argv[i+1]);
    }

    for (int i = 0; i < argc - 1; i++) {
        threads.at(i).join();
    }

    for (int i = 0; i < futures.size(); i++) {
        cout << argv[i + 1] << " : " << futures.at(i).get() << endl;
    }
    return 0;
}

#include "solutions/ex3.h"
