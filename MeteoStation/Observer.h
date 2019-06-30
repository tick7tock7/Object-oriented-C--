#pragma once

#include <string>

class Observer
{
public:
    Observer();
    virtual ~Observer();
    virtual void update(std::string cName, double temperature) = 0;
};
