#include "point.hpp"
#include "segment.hpp"
#include "triangle.hpp"
#include <iostream>
using namespace std;


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
