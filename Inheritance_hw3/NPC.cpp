#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "NPC.h"

using namespace std;

NPC::NPC(string na, Point2D* P) : Entity(na, P)
{

}

NPC::~NPC()
{

}

bool NPC::isAlive() const
{
    return true;
}

void NPC::print() const
{
    this->get_Name();
}
