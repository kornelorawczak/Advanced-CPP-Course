#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <ios>
#include "input.hpp"

using namespace std;

string Input::decrypt(const string &text) {
    string result = text;
    for (char& c : result){
        if (isalpha(c)){
            char base = islower(c) ? 'a' : 'A';
            if (c - key >= base){
                c -= key;
            }
            else {
                c = c - key + 26;
            }
        }
    }
    return result;
}
Input::Input(const string &filename) : key(0){
    file.open(filename);
    if(!file.is_open()){
        throw ios_base::failure("Unable to open read file");
    }
    file.exceptions(ifstream::badbit | ifstream::failbit);
}
Input::~Input(){
    file.close();
}
void Input::setkey(int k){
    key = k % 26;
}
string Input::read(){
    string line;
    if (getline(file, line)){
        return decrypt(line);
    }
    else{
        throw ios_base::failure("Error reading from file");
    }
}

