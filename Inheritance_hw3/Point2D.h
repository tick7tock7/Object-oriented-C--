#ifndef Point2D_H_
#define Point2D_H_

#include<iostream>
#include<cmath>

using namespace std;

class Point2D
{
protected:
    double x;
    double y;

public:
    Point2D(double = 0.0, double = 0.0);
    Point2D(const Point2D&);
    Point2D& operator=(const Point2D&);
    ~Point2D();

    virtual bool is3D() const;

    double get_X() const;
    double get_Y() const;
    void set_X(double);
    void set_Y(double);

    virtual void setValues(const Point2D*);

    virtual double getDistanceTo(const Point2D*);
};

#endif
