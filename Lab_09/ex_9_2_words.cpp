#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include <cctype>


using namespace std;

/**
 * Removes all non alphanumeric characters from given word and converts to lower case.
 * @param[in,out] word on return word consist only of lower case characters.
 */
void toLowerAlpha(std::string & s1){
    s1.erase(std::remove_if(s1.begin(), s1.end(), [](unsigned char x) { return !std::isalnum(x); }),s1.end());
    //std::transform(s1.begin(), s1.end(), s1.begin(), tolower);
    std::transform(s1.begin(), s1.end(), s1.begin(),
                   [](unsigned char c){ return std::tolower(c); });

}

int main(){
    int count = 0;
    std::string word;
    map<string, int> c;
    std::vector<int> v;
    while( cin >> word) {
       toLowerAlpha(word);

       if(word != ""){
           auto find = c.find(word);
           if (find!= c.end()) {
               (find->second)++;
           } else {
               count++;
               c.emplace(word, 1);
           }

//            if(!c.find(word)) {
//                c.insert(word, 1);
//            }else {
//                c[word]++;
//            }
       }

    }

    //version without iterator
    //multimap<int, string, greater<>> m2; // added greater<> to change order



    multimap<int, string> m2;
    multimap<int, string>::reverse_iterator rit;

    for (auto const &pair: c) {
        m2.insert(std::make_pair(pair.second, pair.first));
    }

    cout << "Number of distinct words : " << count << endl;
    cout << "\nThe top 20 most popular words: \n";

// to version without iterator
//    int iter = 0;
//    for (auto const &pair: m2) {
//        if(iter == 20){
//            break;
//        }
//        std::cout << pair.second << " : " << pair.first  << std::endl;
//        iter++;
//    }

    int iter = 0;
    for (rit=m2.rbegin(); rit!=m2.rend(); ++rit){
        if(iter == 20){
            break;
        }
        cout << rit->second << " : " << rit->first << '\n';
        iter++;
    }
    return 0;

}
/*
 * Expected output for ./words < hamletEN.txt

Number of distinct words : 4726

The top 20 most popular words:
the : 1145
and : 967
to : 745
of : 673
i : 569
you : 550
a : 536
my : 514
hamlet : 465
in : 437
it : 417
that : 391
is : 340
not : 315
lord : 311
this : 297
his : 296
but : 271
with : 268
for : 248
your : 242

 */