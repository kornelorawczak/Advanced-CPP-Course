#include <iostream>
#include <cmath>

using namespace std;

class Line{
private:
    double A, B, C;
public:
    Line(double A, double B, double C) : A(A), B(B), C(C) {
        if (A == 0 && B == 0){
            throw invalid_argument("A and B factor of a Ax + By + C = 0 line cannot equal 0!");
        }
    };
    double* get_factors(){
        static double factors[3] {A,B,C};
        return factors;
    }
};

class Vector{
private:
    pair<double, double> vec;
public:
    Vector(double x, double y) : vec(x,y) {};
    pair<double, double> get_coords(){
        return vec;
    }
};


class Point{
private:
    pair<double, double> coords;
public:
    Point(double x, double y) : coords(x,y) {}
    pair<double, double> get_coords(){
        return coords;
    }
    void translation(Vector v){
        coords.first+=v.get_coords().first;
        coords.second+=v.get_coords().second;
    }
    void rotate(double angle, const Point& center){
        double x = coords.first;
        double y = coords.second;
        double xc = center.coords.first;
        double yc = center.coords.second;
        coords.first = (x - xc) * cos(angle) - (y - yc) * sin(angle) + xc;
        coords.second = (x - xc) * sin(angle) + (y - yc) * cos(angle) + yc;
    }
    void centralSymmetry(const Point& center){
        double xc = center.coords.first;
        double yc = center.coords.second;
        coords.first = 2 * xc - coords.first;
        coords.second = 2 * yc - coords.second;
    }
    void axisSymmetry(Line L){
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
    void print(){
        cout<<"("<<coords.first<<", "<<coords.second<<")"<<endl;
    }
};

double distance(Point A, Point B){
    auto [x1,y1] = A.get_coords();
    auto [x2,y2] = B.get_coords();
    return sqrt(pow(x1-x2,2) + pow(y2-y1,2));
}

class Segment{
private:
    Point X, Y;
public:
    Segment(Point A, Point B) : X(A), Y(B){
        if (A.get_coords() == B.get_coords()){
            throw invalid_argument("Points defining a line cannot be the same!");
        }
    }
    bool belongs(Point Z){
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
    pair<Point, Point> get_points(){
        pair<Point, Point> points(X,Y);
        return points;
    }
    void translation(Vector v){
        X.translation(v);
        Y.translation(v);
    }
    void rotate(double angle, const Point &center){
        X.rotate(angle, center);
        Y.rotate(angle, center);
    }
    void centralSymmetry(const Point &center){
        X.centralSymmetry(center);
        Y.centralSymmetry(center);
    }
    void axisSymmetry(Line L){
       X.axisSymmetry(L);
       Y.axisSymmetry(L);
    }
    void print(){
        cout<<"["<<endl;
        X.print();
        Y.print();
        cout<<"]"<<endl;
    }
};

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

class Triangle{
private:
    Point A, B, C;
    double l1, l2, l3;
public:
    Triangle(Point X, Point Y, Point Z) : A(X), B(Y), C(Z) {
        l1 = distance(X,Y);
        l2 = distance(X,Z);
        l3 = distance(Y,Z);
        if (l1==0 || l2==0 || l3==0 || l1+l2 <= l3 || l2+l3 <= l1 || l1+l3 <= l2){
            throw invalid_argument("Given points doesn't create a triangle!");
        }
    }
    double perimeter() const{
        return l1+l2+l3;
    }
    double field(){
        double p = perimeter()/2;
        return sqrt(p*(p-l1)*(p-l2)*(p-l3));
    }
    bool contains(Point P) {
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
    void translation(Vector v){
        A.translation(v);
        B.translation(v);
        C.translation(v);
    }
    void rotate(double angle, const Point &center){
        A.rotate(angle, center);
        B.rotate(angle, center);
        C.rotate(angle, center);
    }
    void centralSymmetry(const Point &center){
        A.centralSymmetry(center);
        B.centralSymmetry(center);
        C.centralSymmetry(center);
    }
    void axisSymmetry(Line L){
        A.axisSymmetry(L);
        B.axisSymmetry(L);
        C.axisSymmetry(L);
    }
    void print(){
        cout<<"{"<<endl;
        A.print();
        B.print();
        C.print();
        cout<<"}"<<endl;
    }
    Point get_A(){
        return A;
    }
    Point get_B(){
        return B;
    }
    Point get_C(){
        return C;
    }

};

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

int main(){
    Segment line1 = Segment(Point(7,10), Point(1,1));
    cout<<line1.belongs(Point(3,4))<<endl;
    cout<<parallel(line1, Segment(Point(9,10), Point(3,1)))<<endl;
    cout<<perpendicular(Segment(Point(1,3.5), Point(-2,-1)), Segment(Point(3,-4), Point(0,-2)))<<endl;
    cout<<distance(Point(-2,6), Point(0,1))<<endl;
    line1.print();
    line1.translation(Vector(10,3));
    line1.print();
    line1.rotate(85, Point(0,0));
    line1.print();
    Triangle t1 = Triangle(Point(0,3), Point(6,5), Point(-2,-5));
    Triangle t2 = Triangle(Point(-4,4), Point(-7,5), Point(3,9));
    t1.print();
    t1.translation(Vector(5,5));
    t1.print();
    cout<<t1.field()<<endl;
    t1.axisSymmetry(Line(10,1,5));
    t1.print();
    cout<<t1.field()<<endl;
    cout<<contains(t1, t2)<<endl;
    cout<<areDisjoint(t1, t2)<<endl;
    return 0;
}