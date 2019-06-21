#ifndef Entity_H_
#define Entity_H_

#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Point2D.h"

using namespace std;

class Entity
{
private:
    long long id;
    string name;
    Point2D* location;

public:
    enum type
    {
        Player,
        Mob,
        NPC
    };

    Entity(string, Point2D*);
    Entity(const Entity&);
    ~Entity();

    virtual bool isAlive() const;
    double getDistanceTo2D(const Entity&);
    double getDistanceTo(const Entity&);

    Point2D* getLocation() const;
    void moveTo(const Point2D*);
    void moveTo(const Entity&);
    virtual void print() const = 0;
    string get_Name() const;
    virtual void setHealth(int) = 0;
};

#endif
