#include "segment.hpp"
#include "point.hpp"
#include <iostream>



Segment::Segment(Point A, Point B) : X(A), Y(B){
    if (A.get_coords() == B.get_coords()){
        throw invalid_argument("Points defining a line cannot be the same!");
    }
}
bool Segment::belongs(Point Z){
    double zx = Z.get_coords().first;
    double zy = Z.get_coords().second;
    pair<double, double> coordsX = X.get_coords();
    pair<double, double> coordsY = Y.get_coords();
    if (((zx-coordsX.first)/(zy-coordsX.second) == (coordsY.first-coordsX.first)/(coordsY.second-coordsX.second)) \
    && (zx >= min(coordsX.first, coordsY.first)) && (zx <= max(coordsX.first, coordsY.first))){
        return true;
    }
    return false;
}
pair<Point, Point> Segment::get_points(){
    pair<Point, Point> points(X,Y);
    return points;
}
void Segment::translation(Vector v){
    X.translation(v);
    Y.translation(v);
}
void Segment::rotate(double angle, const Point &center){
    X.rotate(angle, center);
    Y.rotate(angle, center);
}
void Segment::centralSymmetry(const Point &center){
    X.centralSymmetry(center);
    Y.centralSymmetry(center);
}
void Segment::axisSymmetry(Line L){
    X.axisSymmetry(L);
    Y.axisSymmetry(L);
}
void Segment::print(){
    cout<<"["<<endl;
    X.print();
    Y.print();
    cout<<"]"<<endl;
}


bool parallel(Segment A, Segment B){
    auto [A1, A2] = A.get_points();
    double x1 = A1.get_coords().first;
    double y1 = A1.get_coords().second;
    double x2 = A2.get_coords().first;
    double y2 = A2.get_coords().second;
    auto [B1, B2] = B.get_points();
    double x3 = B1.get_coords().first;
    double y3 = B1.get_coords().second;
    double x4 = B2.get_coords().first;
    double y4 = B2.get_coords().second;
    if ((x1-x2)/(y1-y2) == (x3-x4)/(y3-y4)){
        return true;
    }
    return false;
}

bool perpendicular(Segment A, Segment B){
    auto [A1, A2] = A.get_points();
    pair<double, double> c1 = A1.get_coords();
    pair<double, double> c2 = A2.get_coords();
    auto [x1, y1] = min(c1, c2);
    auto [x2, y2] = max(c1, c2);
    auto [B1, B2] = B.get_points();
    pair<double, double> c3 = B1.get_coords();
    pair<double, double> c4 = B2.get_coords();
    auto [x3, y3] = min(c3, c4);
    auto [x4, y4] = max(c3, c4);
    double a1 = (x2-x1)/(y2-y1);
    double a2 = (x4-x3)/(y4-y3);
    if (a1 * a2 == -1){
        return true;
    }
    return false;
}