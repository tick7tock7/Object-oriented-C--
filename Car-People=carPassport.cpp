#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

class car
{
private:
    char* brand;
    unsigned int year;
    unsigned int reg_numb;

public:
    car(char* = "", unsigned = 0, unsigned = 0);
    ~car();
    car(const car&);
    car& operator=(const car&);
    void display() const;
};

car::car(char* br, unsigned y, unsigned r_n)
{
    brand = new char[strlen(br)+1];
    assert(brand != NULL);
    strcpy(brand, br);
    year = y;
    reg_numb = r_n;
}

car::~car()
{
    delete [] brand;
}

car::car(const car& c)
{
    brand = new char[strlen(c.brand)+1];
    assert(brand != NULL);
    strcpy(brand, c.brand);
    year = c.year;
    reg_numb = c.reg_numb;
}

car& car::operator=(const car& c)
{
    if(this != &c)
    {
        delete [] brand;
        brand = new char[strlen(c.brand)+1];
        assert(brand != NULL);
        strcpy(brand, c.brand);
        year = c.year;
        reg_numb = c.reg_numb;
    }
    return *this;
}

void car::display() const
{
    cout << brand << endl;
    cout << year << endl;
    cout << reg_numb << endl;
}

class people
{
private:
    char* name;
    char* ucn;

public:
    people(char * = "", char * = "");
    ~people();
    people(const people&);
    people& operator=(const people& p);
    void display() const;
};

people::people(char *na, char *uc)
{
    name = new char[strlen(na)+1];
    assert(name != NULL);
    strcpy(name, na);
    ucn = new char[strlen(uc)+1];
    assert(ucn != NULL);
    strcpy(ucn, uc);
}

people::~people()
{
    delete [] name;
    delete [] ucn;
}

people::people(const people& p)
{
    name = new char[strlen(p.name)+1];
    assert(name != NULL);
    strcpy(name, p.name);
    ucn = new char[strlen(p.ucn)+1];
    assert(ucn != NULL);
    strcpy(ucn, p.ucn);
}

people& people::operator=(const people& p)
{
    if(this != &p)
    {
        delete [] name;
        delete [] ucn;
        name = new char[strlen(p.name)+1];
        assert(name != NULL);
        strcpy(name, p.name);
        ucn = new char[strlen(p.ucn)+1];
        assert(ucn != NULL);
        strcpy(ucn, p.ucn);
    }
    return *this;
}

void people::display() const
{
    cout << name << endl;
    cout << ucn << endl;
}

class carPassport: public car, public people
{
public:
    carPassport(char* = "", unsigned = 0, unsigned = 0,
                char* = "", char* = "");
    ~carPassport();
    carPassport(const carPassport&);
    carPassport& operator=(const carPassport&);
    void display() const;
};

carPassport::carPassport(char* brand, unsigned year, unsigned reg_numb,
                         char* name, char* ucn) : car(brand, year, reg_numb), people(name, ucn)
{

}

carPassport::~carPassport()
{

}

carPassport::carPassport(const carPassport& cp) : car(cp), people(cp)
{

}

carPassport& carPassport::operator=(const carPassport& cp)
{
    if(this != cp)
    {
        car::operator=(cp);
        people::operator=(cp);
    }
    return *this;
}

void carPassport::display() const
{
    car::display();
    people::display();
}

int main()
{
    carPassport x("FORD FIESTA", 2006, 4414,
                  "Plamen", "2346378");
    x.display();

    return 0;
}
