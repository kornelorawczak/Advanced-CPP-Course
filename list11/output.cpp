#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <ios>
#include "output.hpp"
using namespace std;

string Output::encrypt(const string &text) {
    string result = text;
    for (char &c : result){
        if (isalpha(c)){
            char last = islower(c) ? 'z' : 'Z';
            if (c + key <= last){
                c += key;
            }
            else{
                c = c + key - 26;
            }
        }
    }
    return result;
}
Output::Output(const string &filename) : key(0) {
    file.open(filename);
    if(!file.is_open()){
        throw ios_base::failure("Unable to open file for writing");
    }
    file.exceptions(ofstream::badbit | ofstream::failbit);
}
Output::~Output(){
    file.close();
}
void Output::setkey(int k){
    key = k % 26;
}
void Output::write(const string &text){
    file << encrypt(text) << endl;
}


