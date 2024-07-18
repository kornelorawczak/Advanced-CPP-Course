#include "point.hpp"
#include <cmath>
#include<iostream>


Point::Point(double x, double y) : coords(x,y) {}
pair<double, double> Point::get_coords(){
    return coords;
}
void Point::translation(Vector v){
    coords.first+=v.get_coords().first;
    coords.second+=v.get_coords().second;
}
void Point::rotate(double angle, const Point& center){
    double x = coords.first;
    double y = coords.second;
    double xc = center.coords.first;
    double yc = center.coords.second;
    coords.first = (x - xc) * cos(angle) - (y - yc) * sin(angle) + xc;
    coords.second = (x - xc) * sin(angle) + (y - yc) * cos(angle) + yc;
}
void Point::centralSymmetry(const Point& center){
    double xc = center.coords.first;
    double yc = center.coords.second;
    coords.first = 2 * xc - coords.first;
    coords.second = 2 * yc - coords.second;
}
void Point::axisSymmetry(Line L){
    double A = L.get_factors()[0];
    double B = L.get_factors()[1];
    double C = L.get_factors()[2];
    double x = coords.first;
    double y = coords.second;
    double numerator_x = x * (B * B - A * A) - 2 * A * B * y - 2 * A * C;
    double numerator_y = y * (A * A - B * B) - 2 * A * B * x - 2 * B * C;
    double denominator = A * A + B * B;
    coords.first = numerator_x / denominator;
    coords.second = numerator_y / denominator;
}
void Point::print(){
    cout<<"("<<coords.first<<", "<<coords.second<<")"<<endl;
}


double distance(Point A, Point B){
    auto [x1,y1] = A.get_coords();
    auto [x2,y2] = B.get_coords();
    return sqrt(pow(x1-x2,2) + pow(y2-y1,2));
}