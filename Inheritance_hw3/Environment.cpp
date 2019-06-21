#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Point3D.h"
#include "Environment.h"

using namespace std;

Environment::Environment()
{
    vector<Entity*> entities;
}

Environment::~Environment()
{

}

void Environment::add(Entity* A)
{
    entities.push_back(A);
}

void Environment::removeAt(int index)
{
    entities.erase(entities.begin()+index-1);
}

Entity* Environment::getAt(int index) const
{
    return entities.at(index);
}

/*void Environment::generateEntities()
{
    Point2D P = Point2D(3.5, 10);
    Mob Mo = Mob("Mobov", &P, 10, 170);
    entities.push_back(Mo*);
    Print3D Po = Point3D(4, 10, 8);
    NPC Ni = NPC("NPCC", &Po);
    entities.push_back(Po*);
}*/

void Environment::destroyEntities()
{
    entities.clear();
}

Entity& Environment::getClosestAliveEntity(const Player& player, Entity::type type) const {
    Entity* closest = entities[0];
    for (int i = 0; i < entities.size(); i++) {
        if (entities[i]->getDistanceTo(player) < closest->getDistanceTo(player)) {
            if (entities[i]->isAlive()) {
                closest = entities[i];
            }
        }
    }

    return *closest;
}
