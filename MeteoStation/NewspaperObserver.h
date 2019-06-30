#pragma once

#include "Observer.h"
#include <string>

class NewspaperObserver : public Observer
{
private:
    std::string name;
    std::string city;
    double temperature;

public:
    NewspaperObserver();
    NewspaperObserver(std::string cName, std::string cityN, double temp);
    ~NewspaperObserver();
    void update(std::string name, double newTemp);
    void printMeteo() const;
};
