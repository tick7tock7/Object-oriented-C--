#ifndef Player_H
#define Player_H

#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Entity.h"

using namespace std;

class Player : virtual public Entity
{
private:
    int damage;
    int health;
    type Type = type::Player;

public:
    Player(string, Point2D*, int, int);
    ~Player();

    bool isAlive() const override;

    template<typename T>
    void attack(T& H)
    {
        if(this->getDistanceTo(H) < 5)
        {
            H.setHealth(this->damage);
        }
    }
    void setHealth(int) override;

    void print() const override;
};

#endif
