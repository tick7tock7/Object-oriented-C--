#include<iostream>
#include<cmath>

#include "Point3D.h"

using namespace std;

Point3D::Point3D() : Point2D()
{
    z = 0.0;
}

Point3D::Point3D(double x, double y, double z) : Point2D(x, y)
{
    this->z = z;
}

Point3D::Point3D(const Point3D& P) : Point2D(P)
{
    z = P.z;
}

Point3D::~Point3D()
{

}

bool Point3D::is3D() const
{
    return 1;
}

Point3D& Point3D::operator=(const Point3D& P)
{
    if(this != &P)
    {
        Point2D::operator=(P);
        z = P.z;
    }

    return *this;
}

double Point3D::get_Z() const
{
    return z;
}

void Point3D::set_Z(double z)
{
    this->z = z;
}

void Point3D::setValues(const Point2D* P)
{
    if(P->is3D())
    {
        Point3D* p3d = (Point3D*)P;
        this->x = p3d->get_X();
        this->y = p3d->get_Y();
        this->z = p3d->get_Z();
    }
    else
    {
        this->x = P->get_X();
        this->y = P->get_Y();
    }
}

double Point3D::getDistanceTo(const Point2D* P)
{
    if(P->is3D())
    {
        Point3D* p3d = (Point3D*)P;
        return sqrt((x - p3d->x)*(x - p3d->x) + (y - p3d->y)*(y - p3d->y) + (z - p3d->z)*(z - p3d->z));
    }
    else
    {
        double X = P->get_X();
        double Y = P->get_Y();
        return sqrt((x - X)*(x - X) + (y - Y)*(y - Y));
    }
}

