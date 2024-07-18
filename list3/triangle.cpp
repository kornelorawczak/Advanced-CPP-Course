#include "triangle.hpp"
#include "point.hpp"
#include <iostream>
#include <cmath>


Triangle::Triangle(Point X, Point Y, Point Z) : A(X), B(Y), C(Z) {
    l1 = distance(X,Y);
    l2 = distance(X,Z);
    l3 = distance(Y,Z);
    if (l1==0 || l2==0 || l3==0 || l1+l2 <= l3 || l2+l3 <= l1 || l1+l3 <= l2){
        throw invalid_argument("Given points doesn't create a triangle!");
    }
}
double Triangle::perimeter() const{
    return l1+l2+l3;
}
double Triangle::field(){
    double p = perimeter()/2;
    return sqrt(p*(p-l1)*(p-l2)*(p-l3));
}
bool Triangle::contains(Point P) {
    double lambda1 = ((B.get_coords().second - C.get_coords().second) * (P.get_coords().first - C.get_coords().first) +
                      (C.get_coords().first - B.get_coords().first) * (P.get_coords().second - C.get_coords().second)) /
                     ((B.get_coords().second - C.get_coords().second) * (A.get_coords().first - C.get_coords().first) +
                      (C.get_coords().first - B.get_coords().first) * (A.get_coords().second - C.get_coords().second));
    double lambda2 = ((C.get_coords().second - A.get_coords().second) * (P.get_coords().first - C.get_coords().first) +
                      (A.get_coords().first - C.get_coords().first) * (P.get_coords().second - C.get_coords().second)) /
                     ((B.get_coords().second - C.get_coords().second) * (A.get_coords().first - C.get_coords().first) +
                      (C.get_coords().first - B.get_coords().first) * (A.get_coords().second - C.get_coords().second));
    double lambda3 = 1.0 - lambda1 - lambda2;
    return (lambda1 > 0 && lambda2 > 0 && lambda3 > 0);
}
void Triangle::translation(Vector v){
    A.translation(v);
    B.translation(v);
    C.translation(v);
}
void Triangle::rotate(double angle, const Point &center){
    A.rotate(angle, center);
    B.rotate(angle, center);
    C.rotate(angle, center);
}
void Triangle::centralSymmetry(const Point &center){
    A.centralSymmetry(center);
    B.centralSymmetry(center);
    C.centralSymmetry(center);
}
void Triangle::axisSymmetry(Line L){
    A.axisSymmetry(L);
    B.axisSymmetry(L);
    C.axisSymmetry(L);
}
void Triangle::print(){
    cout<<"{"<<endl;
    A.print();
    B.print();
    C.print();
    cout<<"}"<<endl;
}
Point Triangle::get_A(){
    return A;
}
Point Triangle::get_B(){
    return B;
}
Point Triangle::get_C(){
    return C;
}



bool areDisjoint(Triangle t1, Triangle t2) {
    Point A1 = t1.get_A();
    Point A2 = t1.get_B();
    Point A3 = t1.get_C();
    Point B1 = t2.get_A();
    Point B2 = t2.get_B();
    Point B3 = t2.get_C();
    if (t1.contains(B1) || t1.contains(B2) || t1.contains(B3) ||
        t2.contains(A1) || t2.contains(A2) || t2.contains(A3)) {
        return false;
    }
    return true;
}

bool contains(Triangle t1, Triangle t2) {
    Point B1 = t2.get_A();
    Point B2 = t2.get_B();
    Point B3 = t2.get_C();
    if (t1.contains(B1) && t1.contains(B2) && t1.contains(B3)) {
        return true;
    }
    return false;
}
