#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <ios>
using namespace std;

class Output{
private:
    ofstream file;
    int key;
    string encrypt(const string &text);
public:
    Output(const string &filename) ;
    ~Output();
    void setkey(int k);
    void write(const string &text);
};
