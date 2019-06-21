#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Player.h"

using namespace std;

Player::Player(string na, Point2D* P, int dam, int he) : Entity(na, P)
{
    damage = dam;
    health = he;
}

Player::~Player()
{

}

bool Player::isAlive() const
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

void Player::setHealth(int a)
{
    this->health -= a;
}

void Player::print() const
{
    cout << this->damage << endl;
    cout << this->health << endl;
}
