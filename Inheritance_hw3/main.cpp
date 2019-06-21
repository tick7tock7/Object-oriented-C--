#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#include "Point2D.h"
#include "Point3D.h"
#include "Player.h"
#include "Environment.h"

using namespace std;

int main()
{
    Point2D* pointer1;
    Point3D* pointer2;

    Point2D p2d = Point2D(4, 8);
    Point2D p5d = Point2D(10, 15);
    Point3D p3d = Point3D(6, 9, 12);
    Point3D p4d = Point3D(10, 11, 15);

    pointer1 = &p2d;
    pointer2 = &p3d;
    cout << "START" << endl;
    cout << pointer1->getDistanceTo(&p4d) << endl;
    //cout << pointer2->getDistanceTo(&p5d) << endl;

    Player Player1 = Player("Player1", &p2d, 10, 100);
    Player Ent2 = Player("name2", &p5d, 50, 150);

    Mob Mob1 = Mob("Mob12", &p4d, 20, 200);

    Player1.attack(Mob1);

    return 0;
}
