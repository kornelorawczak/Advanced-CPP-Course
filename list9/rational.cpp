#include <iostream>
#include <cmath>
#include <stdexcept>
#include <unordered_map>
#include "rational.hpp"

using namespace std;

namespace calculations {

    int Rational::GCD(int a, int b) {
        while (a != b) {
            if (a > b) a -= b;
            else b -= a;
        }
        return a;
    }

    Rational::Rational(int n, int d) {
            if (d == 0) throw Division_by_0();
            numerator = n / GCD(n, d);
            denominator = d / GCD(n, d);
            if (denominator < 0) {
                denominator *= (-1);
                numerator *= (-1);
            }
        }

    Rational::Rational(int n) : Rational(n, 1) {}

    Rational::Rational() : Rational(0, 1) {}

        int Rational::get_n() const { return numerator; }

        int Rational::get_d() const { return denominator; }

        Rational &Rational::operator+=(const Rational &other) {
            *this = *this + other;
            return *this;
        }

        Rational &Rational::operator-=(const Rational &other) {
            *this = *this - other;
            return *this;
        }

        Rational &Rational::operator*=(const Rational &other) {
            *this = *this * other;
            return *this;
        }

        Rational &Rational::operator/=(const Rational &other) {
            if (other.numerator == 0) throw Division_by_0();
            *this = *this / other;
            return *this;
        }

        Rational Rational::operator-() {
            numerator *= (-1);
            return *this;
        }

        Rational Rational::operator!() {
            int placeholder = denominator;
            denominator = numerator;
            numerator = placeholder;
            return *this;
        }

    Rational::operator double() const {
            return static_cast<double>(numerator) / denominator;
        }

        Rational::operator int() const {
            if (abs(numerator) > INT_MAX / denominator) throw Out_of_range();
            return round(double());
        }

    };


    calculations::Rational calculations::operator+(const Rational &q1, const Rational &q2) {
        int d1 = q1.get_d();
        int n1 = q1.get_n();
        int d2 = q2.get_d();
        int n2 = q2.get_n();
        int new_d = d1 * d2;
        int new_n = n1 * d2 + n2 * d1;
        return Rational(new_n, new_d);
    }

    calculations::Rational calculations::operator-(const Rational &q1, const Rational &q2) {
        int d1 = q1.get_d();
        int n1 = q1.get_n();
        int d2 = q2.get_d();
        int n2 = q2.get_n();
        int new_d = d1 * d2;
        int new_n = n1 * d2 - n2 * d1;
        return Rational(new_n, new_d);
    }

    calculations::Rational calculations::operator*(const Rational &q1, const Rational &q2) {
        int d1 = q1.get_d();
        int n1 = q1.get_n();
        int d2 = q2.get_d();
        int n2 = q2.get_n();
        return Rational(n1 * n2, d1 * d2);
    }

    calculations::Rational calculations::operator/(const Rational &q1, const Rational &q2) {
        int d1 = q1.get_d();
        int n1 = q1.get_n();
        int d2 = q2.get_d();
        int n2 = q2.get_n();
        return Rational(n1 * d2, n2 * d1);
    }

    ostream &calculations::operator<<(ostream &out, const Rational &q) {
        string result;
        int intPart = q.numerator / q.denominator;
        int rest = q.numerator % q.denominator;
        result += to_string(intPart);
        if (rest == 0) {
            out << result;
            return out;
        } else {
            result += ".";
            rest = abs(rest);
            unordered_map<int, int> remainders;
            while (rest != 0) {
                // if remainder repeats, it's a recurring decimal
                if (remainders.find(rest) != remainders.end()) {
                    result.insert(remainders[rest], "(");
                    result += ")";
                    break;
                }
                remainders[rest] = result.size();
                rest *= 10;
                int quotient = rest / q.denominator;
                result += to_string(quotient);
                rest %= q.denominator;
            }
            out << result;
            return out;
        }
    }
