#include<iostream>
#include<cmath>

#include "Point2D.h"

Point2D::Point2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point2D::Point2D(const Point2D& P)
{
    x = P.x;
    y = P.y;
}

Point2D::~Point2D()
{

}

bool Point2D::is3D() const
{
    return 0;
}

Point2D& Point2D::operator=(const Point2D& P)
{
    if(this != &P)
    {
        x = P.x;
        y = P.y;
    }

    return *this;
}

double Point2D::get_X() const
{
    return x;
}

double Point2D::get_Y() const
{
    return y;
}

void Point2D::set_X(double x)
{
    this->x = x;
}

void Point2D::set_Y(double y)
{
    this->y = y;
}

void Point2D::setValues(const Point2D* P)
{
    set_X(P->x);
    set_Y(P->y);
}

double Point2D::getDistanceTo(const Point2D* P)
{
    return sqrt((x - P->x)*(x - P->x) + (y - P->y)*(y - P->y));
}
