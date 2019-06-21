#ifndef Point3D_H_
#define Point3D_H_

#include<iostream>
#include<cmath>

#include "Point2D.h"

using namespace std;

class Point3D : public Point2D
{
private:
    double z;

public:
    Point3D();
    Point3D(double, double, double);
    Point3D(const Point3D&);
    Point3D& operator=(const Point3D&);
    ~Point3D();

    bool is3D() const override;

    double get_Z() const;
    void set_Z(double);

    void setValues(const Point2D*) override;

    double getDistanceTo(const Point2D*) override;
};

#endif
