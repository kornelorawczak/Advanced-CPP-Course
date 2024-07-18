#ifndef POINT_HPP
#define POINT_HPP
#include <utility>
#include "other.hpp"
using namespace std;

class Point {
private:
    pair<double, double> coords;
public:
    Point(double x, double y);

    pair<double, double> get_coords();

    void translation(Vector v);

    void rotate(double angle, const Point &center);

    void centralSymmetry(const Point &center);

    void axisSymmetry(Line L);

    void print();
};

double distance(Point A, Point B);

#endif