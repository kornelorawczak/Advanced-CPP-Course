#ifndef OTHER_HPP
#define OTHER_HPP
#include <utility>

using namespace std;
class Line{
        private:
        double A, B, C;
        public:
        Line(double A, double B, double C);
        double* get_factors();
};
class Vector{
private:
    pair<double, double> vec;
public:
    Vector(double x, double y);
    pair<double, double> get_coords();
};

#endif