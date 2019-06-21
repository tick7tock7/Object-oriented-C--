#ifndef Mob_H
#define Mob_H

#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Player.h"
#include "Entity.h"

using namespace std;

class Mob : virtual public Entity
{
private:
    int damage;
    int health;
    type Type = type::Mob;

public:
    Mob(string, Point2D*, int, int);
    ~Mob();

    bool isAlive() const override;

    void attack(Entity&);
    void setHealth(int) override;

    void print() const override;
};

#endif
