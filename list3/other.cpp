# include "other.hpp"
#include <iostream>
#include <cmath>

using namespace std;


Line::Line(double A, double B, double C) : A(A), B(B), C(C) {
    if (A == 0 && B == 0){
        throw invalid_argument("A and B factor of a Ax + By + C = 0 line cannot equal 0!");
    }
};
double* Line::get_factors(){
    static double factors[3] {A,B,C};
    return factors;
}

Vector::Vector(double x, double y) : vec(x,y) {};
pair<double, double> Vector::get_coords(){
    return vec;
}

