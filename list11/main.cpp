#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <ios>
#include "input.hpp"
#include "output.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file> <key>" << endl;
        return 1;
    }

    string input_file = argv[1];
    string output_file = argv[2];
    int key = stoi(argv[3]);
    try {
        Input input(input_file);
        input.setkey(key);
        Output output(output_file);
        output.setkey(key);
        string line;

        while(true){
            try{
                line = input.read();
                output.write(line);
            }
            catch (const ios_base::failure &){
                break;
            }
        }
    }
    catch (const exception &e){
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
