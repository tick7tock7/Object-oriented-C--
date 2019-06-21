#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Entity.h"

using namespace std;

class NPC : virtual public Entity
{
private:
    type Type = type::NPC;
public:
    NPC(string, Point2D*);
    ~NPC();

    bool isAlive() const override;

    void print() const override;
};

