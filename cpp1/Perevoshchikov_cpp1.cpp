#include <iostream>
#include <cmath>
#include <vector>
//#include "point.h"
#include "point.cpp"
//#include "broken.h"
#include "broken.cpp"
#include "lockbroken.cpp"
#include "polygon.cpp"
#include "triangle.cpp"
#include "trapezoid.cpp"
#include "regular_polygon.h"

std::ostream& operator<<(std::ostream &o, Point &a){
    o << a.getX() << " " << a.getY() << std::endl;
    return o;
}

int main(int argc, char** argv) {
/*	test a;
a.m[0]=33;
cout<<a.m[0]<<endl;
test b(a);
cout<<b.m[0]<<endl;
a.m[0]=35;
cout<<a.m[0]<<endl;
cout<<b.m[0]<<endl;*/
Broken broken;
Point a(1, 0);
Point b(0, 1);
Point c(-1, 0);
Point d(0, -1);
Point arr[4];
arr[0] = a;
arr[1] = b;
arr[2] = c;
arr[3] = d;
LockBroken lockbroken;
Polygon polugon;
Triangle triangle;
Trapezoid trapezoid;
Regular_Polygon regular;
//arr[3] = d;
//Polygon shape(arr, 4); 
//std::cout << "S="<<shape.getS()<< " P=" << shape.getLength() << std::endl;
// cout<<a.getX()<<" "<<a.getY()<<endl;
// Point b((float)1,(float)2);
// cout<<b.getX()<<" "<<b.getY()<<endl;
// Point c(b);
// cout<<c.getX()<<" "<<c.getY()<<endl;
// Point d=b;
// cout<<d.getX()<<" "<<d.getY()<<endl;
// cout<<d.ToZero()<<endl;
// Point *e=new Point();
//delete(e);
return 0;
}
