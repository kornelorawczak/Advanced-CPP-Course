#include <iostream>
#include <cmath>
#include <stdexcept>
#include <unordered_map>
#include "rational.hpp"
using namespace std;



int main() {
    calculations::Rational r1 = calculations::Rational(1,3);
    cout << r1 << endl;
    calculations::Rational r2 = calculations::Rational(2359348,99900);
    cout << r2 << endl;
    return 0;
}
