#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<iomanip>

const int MAX_SIZE = 50;

class Worker
{
private:
    char* name;
    double salary;

public:
    Worker(const char* = "", double = 0.0);
    Worker(const Worker&);
    ~Worker();
    Worker& operator=(const Worker&);
    void print() const;
    double get_Salary() const;
};

Worker::Worker(const char* n, double s)
{
    name = new char[strlen(n)+1];
    if(!name)
        exit(1);
    strcpy(name, n);
    salary = s;
}

Worker::Worker(const Worker& w)
{
    name = new char[strlen(w.name)+1];
    if(!name)
        exit(1);
    strcpy(name, w.name);
    salary = w.salary;
}

Worker::~Worker()
{
    delete [] name;
}

Worker& Worker::operator=(const Worker& w)
{
    if(this != &w)
    {
        delete [] name;
        name = new char[strlen(w.name)+1];
        if(!name)
            exit(1);
        strcpy(name, w.name);
        salary = w.salary;
    }
    return *this;
}

void Worker::print() const
{
    cout << name << endl
         << salary << endl;
}

double Worker::get_Salary() const
{
    return salary;
}

class HourlyWorker : public Worker
{
private:
    char* work;
    int hours;

public:
    HourlyWorker(const char* = "", double = 0.0,
                 const char* = "", int = 0);
    HourlyWorker(const HourlyWorker&);
    ~HourlyWorker();
    HourlyWorker& operator=(const HourlyWorker&);
    double WeekSalary() const;
    void print() const;
};

HourlyWorker::HourlyWorker(const char* n, double s,
                           const char* w, int h) : Worker(n, s)
{
    work = new char[strlen(w)+1];
    if(!work)
        exit(1);
    strcpy(work, w);
    hours = h;
}

HourlyWorker::HourlyWorker(const HourlyWorker& p) : Worker(p)
{
    hours = p.hours;
    work = new char[strlen(p.work)+1];
    if(!work)
        exit(1);
    strcpy(work, p.work);
}

HourlyWorker::~HourlyWorker()
{
    delete [] work;
}

HourlyWorker& HourlyWorker::operator=(const HourlyWorker& p)
{
    if(this != &p)
    {
        Worker::operator=();
        delete [] work;
        hours = p.hours;
        work = new char[strlen(p.work)+1];
        if(!work)
            exit(1);
        strcpy(work, p.work);
    }
    return *this;
}

double HourlyWorker::WeekSalary() const
{
    double x;
    double y = get_Salary();
    if(hours <= 40)
        x = hours * y;
    else if(hours <= 60)
        x = 40*y + (hours-40)*1.5*y;
    else
        x = 40*y + 20*1.5*y + (hours-60)*2*y;
    return x;
}

void HourlyWorker::print() const
{
    Worker::print();
    cout << hours << endl
         << work << endl
         << WeekSalary() << endl;
}

class SalariedWorker : public Worker
{
private:
    char* work;
    int hours;

public:
    SalariedWorker(const char* = "", double = 0.0
                     const char = "", int = 0);
    SalariedWorker(const SalariedWorker&);
    ~SalariedWorker();
    SalariedWorker& operator=(const SalariedWorker&);
    double WeekSalary() const;
    void print() const;
};

SalariedWorker::SalariedWorker(const char* n, double s,
                               const char* w, int h) : Worker(n, s)
{
    work = new char[strlen(w)+1];
    if(!work)
        exit(1);
    strcpy(work, w);
    hours = h;
}

SalariedWorker::SalariedWorker(const SalariedWorker& p) : Worker(p)
{
    hours = p.hours;
    work = new char[strlen(p.work)+1];
    if(!work)
        exit(1);
    strcpy(work, p.work);
}

SalariedWorker::~SalariedWorker()
{
    delete [] work;
}

SalariedWorker& SalariedWorker::operator=(const SalariedWorker& p)
{
    if(this != &p)
    {
        Worker::operator=(p);
        delete [] work;
        work = new char[strlen(p.work)+1];
        if(!work)
            exit(1);
        strcpy(work, p.work);
        hours = p.hours;
    }
    return *this;
}

double SalariedWorker::WeekSalary() const
{
    return 40 * get_Salary();
}

void SalariedWorker::print() const
{
    Worker::print();
    cout << hours << endl
         << work << endl
         << WeekSalary() << endl;
}

void Create_HourlyWorker_arr(int m, HourlyWorker**& arr)
{
    arr = new HourlyWorker*[m];
    if(!arr)
        exit(1);
    for(int i = 0; i < m; i++)
    {
        char n[MAX_SIZE];
        cin.getline(n, MAX_SIZE);
        double s;
        cin >> s;
        cin.ignore();
        char w[MAX_SIZE];
        cin.getline(w, MAX_SIZE);
        int h;
        cin >> h;
        cin.ignore();
        arr[i] = new HourlyWorker(n, s, w, h);
        if(!arr[i])
            exit(1);
    }
}

void Print_HourlyWorker_arr(int n, HourlyWorker** arr)
{
    for(int i = 0; i < n; i++)
        arr[i]->print();
}

void Sort_HourlyWorker_arr(int n, HourlyWorker** arr)
{
    for(int i = 0; i < n-1; i++)
    {
        int k = i;
        double max = arr[i]->WeekSalary();
        for(int j = i+1; j < n; j++)
        {
            if(arr[j]->WeekSalary() > max)
            {
                max = arr[j]->WeekSalary();
                k = j;
            }
        }
        HourlyWorker* ptr = arr[i];
        arr[i] = arr[k];
        arr[k] = ptr;
    }
}

void Delete_HourlyWorker_arr(int n, HourlyWorker** arr)
{
    for(int i = 0; i < n; i++)
        delete arr[i];
    delete [] arr;
}



int main()
{
    return 0;
}
