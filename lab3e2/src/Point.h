#ifndef POINT_H_
#define POINT_H_

class Point{
private:
    double x;
    double y;

public:
    Point();
    Point(double, double);
    double getX() const;
    double getY() const;
};

#endif /* POINT_H_ */
