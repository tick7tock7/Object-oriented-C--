#include<iostream>
#include<cstring>

using namespace std;

class Person
{
private:
    char* name;
    char* egn;

public:
    void readPerson(char*, char*);
    void printPerson() const;
};

void Person::readPerson(char *str, char *num)
{
    name = new char[strlen(str) + 1];
    strcpy(name, str);
    egn = new char[11];
    strcpy(egn, num);
}

void Person::printPerson() const
{
    cout << name << endl;
    cout << egn << endl;
}

class Student : Person
{
private:
    long facnom;
    double usp;

public:
    void readStudent(char*, char*, long, double);
    void printStudent() const;
};

void Student::readStudent(char *str, char *num, long facn, double u)
{
    readPerson(str, num);
    facnom = facn;
    usp = u;
}

void Student::printStudent() const
{
    printPerson();
    cout << facnom << endl;
    cout << usp << endl;
}

class PStudent : public Student
{
private:
    double tax;

public:
    void readPStudent(char*, char*, long, double, double);
    void printPStudent() const;
};

void PStudent::readPStudent(char *str, char *num, long facn, double u, double t)
{
    readStudent(str, num, facn, u);
    tax = t;
}

void PStudent::printPStudent() const
{
    printPStudent();
    cout << tax << endl;
}

int main()
{
    PStudent stud;
    stud.readPStudent("I I", "62035089011", 42444, 5.50, 500.15);
    stud.printPStudent();

    return 0;
}
