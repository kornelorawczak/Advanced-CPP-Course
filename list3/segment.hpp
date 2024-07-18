#include "point.hpp"


class Segment{
private:
    Point X, Y;
public:
    Segment(Point A, Point B);
    bool belongs(Point Z);
    pair<Point, Point> get_points();
    void translation(Vector v);
    void rotate(double angle, const Point &center);
    void centralSymmetry(const Point &center);
    void axisSymmetry(Line L);
    void print();
};

bool parallel(Segment A, Segment B);

bool perpendicular(Segment A, Segment B);