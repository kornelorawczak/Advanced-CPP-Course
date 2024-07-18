#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <ios>

using namespace std;

class Input {
private:
    ifstream file;
    int key;
    string decrypt(const string &text);
public:
    explicit Input(const string &filename);
    ~Input();
    void setkey(int k);
    string read();
};
