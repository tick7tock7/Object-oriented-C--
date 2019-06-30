#include "NewspaperObserver.h"
#include <iostream>

NewspaperObserver::NewspaperObserver()
{
    name = " ";
    city = " ";
    temperature = 0.0;
}

NewspaperObserver::NewspaperObserver(std::string cName, std::string cityN, double temp)
{
    name = cName;
    city = cityN;
    temperature = temp;
}

NewspaperObserver::~NewspaperObserver()
{

}

void NewspaperObserver::update(std:: string cName, double newTemp)
{
    city = cName;
    temperature = newTemp;
    std::cout << "Update " << name << ": The temperature in " << city << " is " << temperature << std::endl;
}

void NewspaperObserver::printMeteo() const
{
    std::cout << "Newspaper " << name << ": The temperature in " << city << " is " << temperature << std::endl;
}
