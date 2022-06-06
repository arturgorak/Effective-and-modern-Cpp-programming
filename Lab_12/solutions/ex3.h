//
// Created by artem on 06.06.22.
//

#ifndef INC_12_EX3_H
#define INC_12_EX3_H

using namespace std;

auto func(promise<long>* promise, const string& filename) {

    long sum = 0;
    fstream my_file;
    my_file.open(filename, ios::in);

    if (!my_file) {
        cout << "No such file";
    } else {
        char ch;
        while (true) {
            my_file >> ch;
            if (my_file.eof())
                break;
            sum += (int) ch;
        }
    }
    my_file.close();

    promise->set_value(sum);
}


#endif //INC_12_EX3_H
