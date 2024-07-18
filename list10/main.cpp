#include <iostream>
#include "bst.hpp"
using namespace std;



int main() {
    auto bst1 = new bst<int> {1,2,3,4,5,6};
    cout << *bst1 << endl;

    auto bst2 = new bst<int, greater<>> {1,2,3,4,5,6};
    cout << *bst2 << endl;

    auto bst3 = new bst<string> {"a", "x", "d", "cd"};
    cout << *bst3 << endl;

    auto bst4 = new bst<string>;
    *bst4 = *bst3;
    bst4->insert("g");
    bst4->insert("y");
    bst4->insert("ab");
    bst4->remove("a");
    if (bst4->find("cd")) cout << "Works!" << endl;
    cout << *bst4 << endl;

    const char* str1 = "d";
    const char* str2 = "a";
    auto bst6 = new bst<const char*, deref_less<const char>> {str1, str2};
    cout << *bst6 << endl;


    auto bst5 = new bst<int>;
    string command;
    int value;
    while (true){
        cout << "Insert command 'insert' / 'find' / 'remove' / 'print' / 'stop': " << endl;
        cin >> command;
        if (command == "insert"){
            cout << "Input int value you want to insert into bst: " << endl;
            cin >> value;
            bst5->insert(value);
        }
        else if (command == "find"){
            cout << "Input int value you want to find in bst: " << endl;
            cin >> value;
            if (bst5->find(value)) cout << "Value " + to_string(value) + " has been found in bst!" << endl;
            else cout << "Value " + to_string(value) + " hasn't been found in bst :((( " << endl;
        }
        else if (command == "remove"){
            cout << "Input int value you want to try to remove from bst: " << endl;
            cin >> value;
            bst5->remove(value);
        }
        else if (command == "print"){
            cout << "bst: [ ";
            cout << *bst5;
            cout << "]" << endl;
        }
        else {
            break;
        }
    }
    delete bst5;
    delete bst1;
    delete bst2;
    delete bst3;
    delete bst4;
    delete bst6;

    return 0;
}
