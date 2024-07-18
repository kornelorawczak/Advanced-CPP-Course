#include <iostream>
#include <cmath>
#include <stdexcept>
#include <unordered_map>

using namespace std;


namespace calculations {
class Rational_excpetion : public logic_error {
public:
    explicit Rational_excpetion(const string& msg) : logic_error(msg) {}
};

class Out_of_range : public Rational_excpetion {
public:
    Out_of_range() : Rational_excpetion("Out of range error!") {}
};

class Division_by_0 : public Rational_excpetion {
public:
    Division_by_0() : Rational_excpetion("Division by zero error!") {}
};

class Rational{
private:
    int numerator, denominator;
    int GCD(int a, int b);
public:
    Rational(int n, int d);
    Rational(int n);
    Rational();
    int get_n() const;
    int get_d() const;

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);
    Rational operator-();
    Rational operator!();
    operator double() const;
    explicit operator int() const;

    friend Rational operator+(const Rational& q1, const Rational& q2);
    friend Rational operator-(const Rational& q1, const Rational& q2);
    friend Rational operator*(const Rational& q1, const Rational& q2);
    friend Rational operator/(const Rational& q1, const Rational& q2);
    friend ostream& operator<<(ostream& out, const Rational& q);

};



}