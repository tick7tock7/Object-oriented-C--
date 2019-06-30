#pragma once

#include "Observer.h"
#include <string>
#include <vector>

class MeteoStation
{
private:
    std::string city;
    double temperature;
    std::vector<Observer*> mObservers;

public:
    MeteoStation();
    MeteoStation(std::string cityN, double temp);
    ~MeteoStation();
    std::string getCity() const;
    double getTemperature() const;
    void setTemperature(double newTemp);
    void Register(Observer* observer);
    void unregister(Observer* observer);
    void notify() const;
};
