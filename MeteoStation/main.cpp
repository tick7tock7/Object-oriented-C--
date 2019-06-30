#include <iostream>
#include "MeteoStation.h"
#include "NewspaperObserver.h"

using namespace std;

int main()
{
    MeteoStation("Sofia", 29.5);

    NewspaperObserver("Trud", "Sofia", 29.5);


    return 0;
}
