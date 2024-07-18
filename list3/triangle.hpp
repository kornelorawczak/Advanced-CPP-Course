
#include "point.hpp"

class Triangle{
private:
    Point A, B, C;
    double l1, l2, l3;
public:
    Triangle(Point X, Point Y, Point Z);
    double perimeter() const;
    double field();
    bool contains(Point P);
    void translation(Vector v);
    void rotate(double angle, const Point &center);
    void centralSymmetry(const Point &center);
    void axisSymmetry(Line L);
    void print();
    Point get_A();
    Point get_B();
    Point get_C();

};

bool areDisjoint(Triangle t1, Triangle t2);

bool contains(Triangle t1, Triangle t2);

