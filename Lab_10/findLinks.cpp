//
// Created by artem on 23.05.22.
//
#include "iostream"
#include <regex>



using namespace std;


void findRegexes(string s, regex reg, int index){
    auto match_begin = sregex_iterator(s.begin(), s.end(), reg);
    auto match_end = sregex_iterator();

    for (auto i = match_begin; i != match_end; i++) {
        smatch match = *i;
        cout << match[index] << endl;
    }

}

int main(){

    std::string s;
    for (std::string tmp; std::getline(std::cin, tmp);) {
        s += tmp;
    }

    auto flags =
            regex_constants::ECMAScript
            | regex_constants::icase
    //| regex_constants::multiline
    ;

    regex reg1(R"(<a\s+(?:[^>]*?\s+)?href=["'](http[s]?://(?:[a-zA-Z]|[0-9]|[$-_@.&+]|[!*\(\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+)["'])", flags);
    cout << "Links: " << endl;
    findRegexes(s, reg1, 1);


    regex reg2(R"(\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}\b)", flags);
    cout << endl <<  "Emails: " << endl;
    findRegexes(s, reg2, 0);


    return 0;

}
