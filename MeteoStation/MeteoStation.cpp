#include "MeteoStation.h"
#include "Observer.h"

MeteoStation::MeteoStation()
{
    city = " ";
    temperature = 0.0;
}

MeteoStation::~MeteoStation()
{

}

MeteoStation::MeteoStation(std::string cityN, double temp)
{
    city = cityN;
    temperature = temp;
}

std::string MeteoStation::getCity() const
{
    return city;
}

double MeteoStation::getTemperature() const
{
    return temperature;
}

void MeteoStation::setTemperature(double newTemp)
{
    temperature = newTemp;
}

void MeteoStation::Register(Observer* observer)
{
    mObservers.push_back(observer);
}

void MeteoStation::unregister(Observer* observer)
{
    for(std::vector<Observer*>::iterator it = mObservers.begin(); it != mObservers.end(); ++it)
    {
        if(*it != observer)
        {
            mObservers.erase(it);
            break;
        }
    }
}
