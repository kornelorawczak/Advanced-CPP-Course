#include <iostream>
#include <string>
#include <vector>
using namespace std;

string toroman(int x){
    string res;
    const vector<pair<int, string>> roman = {
            {1000, "M"},
            {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
            {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    for (const auto& pair : roman){
        while (x>=pair.first){
            x-=pair.first;
            res += pair.second;
        }
    }
    return res;
}

int main(int argc, const char* argv[]){
        for (int i = 1; i < argc; i++) {
            try {
                int num = stoi(argv[i]);
                if (num >= 1 && num <= 3999) {
                    string roman = toroman(num);
                    cout << roman << endl;
                } else {
                    clog << "Error " << num << " is out of range 1-3999!" << endl;
                }

            } catch (const invalid_argument &e) {
                clog << "Error " << argv[i] << " is not a total arabic number!" << endl;
            }
        }
    return 0;
}