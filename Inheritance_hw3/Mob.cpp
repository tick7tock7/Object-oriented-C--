#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Player.h"
#include "Mob.h"

using namespace std;

Mob::Mob(string na, Point2D* P, int da, int he) : Entity(na, P)
{
    damage = da;
    health = he;
}

Mob::~Mob()
{

}

bool Mob::isAlive() const
{
    if(health > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Mob::attack(Entity& E)
{
    if(this->getDistanceTo(E) < 5)
    {
        E.setHealth(this->damage);
    }
}

void Mob::setHealth(int a)
{
    this->health -= a;
}

void Mob::print() const
{
    cout << this->damage << endl;
    cout << this->health << endl;
}
