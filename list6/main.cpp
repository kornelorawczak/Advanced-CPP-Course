#include <iostream>
#include "poly.hpp"
using namespace std;

int main() {
    poly p1 = {-1,5,-7,2,4};
    poly p2 = {0,5,1,2};
    cout << p1 << endl;
    cout << p2 << endl;
    poly p3 = p1 + p2;
    cout << p3 << endl;
    double coef[] = {1,2,7};
    poly p4 = poly(2, coef);
    poly p6 = p4 * 3;
    cout << p6 << endl;
    poly p7 = p1 * p2;
    cout << p7 << endl;
    p1 -= p7;
    cout << p1 << endl;
    p1 *= p2;
    cout << p1 << endl;
    p1[1] = 20;
    cout << p1 << endl;
    cout << p2(2) << endl;
//    poly p;
//    cin >> p;
//    poly p5 = p1 - p;
//    cout << p5;
    return 0;
}
