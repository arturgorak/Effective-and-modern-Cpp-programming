#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <memory>

using namespace std;
/**
 * Trie structure
 *
 * HINT: use std::map to implement it!
 *       My implementation adds less than 25 lines of code. 
 */
class Trie{
    map<string, Trie> data;
    //map<string, Trie*> data2; //podpowiedzi
    
    bool last;

  /// TODO:
public:

    Trie(){
        last = false;
    }

    static void printSentence(const std::vector<std::string>  & sentence ){
        for(const auto & w : sentence)
            cout << w << " ";
    }
    void add(const std::vector<std::string>  & sentece ){
       cout << "Adding : ";
       printSentence(sentece);
       cout << "\n";

        /// TODO:
        auto trie = this;
        for (auto x : sentece) {
            auto find = trie->data.find(x);
            if (find == trie->data.end()) {
                Trie tmp;
                trie->data.emplace(x, tmp);
            }
            trie = &(trie->data.at(x));

        }
        trie->last = true;

    }
    void printPossibleEndings(const std::vector<std::string>  & beginningOfSentece ){
        cout << "Endings for \"";
        printSentence(beginningOfSentece);
        cout << "\" are :\n";
        // TODO:

        auto trie = this;
        for (auto x : beginningOfSentece) {
            trie = &(trie->data.at(x));
        }

        trie->recursive_reading(" >");
    }

    void recursive_reading(const string result) {
        for (auto [k, v] : data){
            v.recursive_reading(result + " " + k);
        }

        if(this->last){
            cout << result << endl;
        }
    }


    void load(const std::string & fileName){
        ifstream file(fileName);
        if(!file){
            cerr << "Error when openning file " << fileName << endl;
            return;
        }
        string word;
        vector<string> sentence;
        while( file >> word) {
            sentence.push_back(word);
            // is it end of the sentence?
            if(word.find_last_of('.') != string::npos) {
                add(sentence);
                sentence.clear();
            }
        }
    }


};


int main(){
    Trie dictionary;
    dictionary.load("../sample.txt");
    //dictionary.load("hamletEN.txt");

    dictionary.printPossibleEndings({"Curiosity"});
    dictionary.printPossibleEndings({"Curiosity", "killed"});
    dictionary.printPossibleEndings({"The", "mouse","was","killed"});

    /* cout << "Beginning of sentence (ended with single .): ";
    string word;
    vector<string> sentence;
    while(true){
        cin >> word;
        if(word == ".")
            break;
        sentence.push_back(word);
        dictionary.printPossibleEndings(sentence);
    }*/
    return 0;
}
/* Expected output:
Adding : Curiosity killed the cat.
Adding : Curiosity killed the mouse.
Adding : Curiosity saved the cat.
Adding : Curiosity killed the cat and the mouse.
Adding : The cat was killed by curiosity.
Adding : The mouse was killed by cat.
Adding : The mouse was killed by curiosity.
Endings for "Curiosity " are :
 > killed the cat.
 > killed the mouse.
 > killed the cat and the mouse.
 > saved the cat.

Endings for "Curiosity killed " are :
 > killed the cat.
 > killed the mouse.
 > killed the cat and the mouse.

Endings for "The mouse was killed " are :
 > by cat.
 > by curiosity.

 */
