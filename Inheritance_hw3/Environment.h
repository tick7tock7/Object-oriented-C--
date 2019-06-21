#ifndef Environment_H
#define Environment_H

#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include "Entity.h"

class Environment
{
private:
    vector <Entity *> entities;

public:
    Environment();
    ~Environment();

    void add(Entity*);
    Entity* getAt(int index) const;
    void removeAt(int);
    void generateEntities();
    void destroyEntities();
    Entity& getClosestAliveEntity(const Player&, Entity::type) const;
};

#endif
