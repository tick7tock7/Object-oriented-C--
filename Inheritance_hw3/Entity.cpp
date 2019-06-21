#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>

#include "Entity.h"

using namespace std;

Entity::Entity(string na, Point2D* P)
{
    id = rand();
    name = na;

    this->location = P;
}

Entity::Entity(const Entity& E)
{
    id = E.id;
    name = E.name;
    location = E.location;
}

Entity::~Entity()
{

}

bool Entity::isAlive() const
{
    return true;
}

Point2D* Entity::getLocation() const
{
    return location;
}

double Entity::getDistanceTo2D(const Entity& E)
{
    return this->location->getDistanceTo(E.getLocation());
}

double Entity::getDistanceTo(const Entity& E)
{
    return this->location->getDistanceTo(E.getLocation());
}

void Entity::moveTo(const Point2D* P)
{
    this->location->setValues(P);
}

void Entity::moveTo(const Entity& E)
{
    this->moveTo(E.getLocation());
}

string Entity::get_Name() const
{
    return this->name;
}
