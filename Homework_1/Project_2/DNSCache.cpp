#include <iostream>
#include <cstring>
#include <cstdlib>

#include "DNSCache.h"

DNSCache& DNSCache::operator=(DNSCache const& c)
{
	if (this != &c) {
		maxOpenPages = c.maxOpenPages;
		currentOpenPages = c.currentOpenPages;
		delete[] list;
		list = new DNSRecord[maxOpenPages];
		for (int i = 0; i <= currentOpenPages; i++)
			list[i] = c.list[i];
	}
	return *this;
}

int DNSCache::findWebAddress(char* DomainName) const
{
	for (int i = 0; i <= currentOpenPages; i++)
		if (strcmp(list[i].getDomainName(), DomainName) == 0)
            return i;

	return -1;
}

const char* DNSCache::lookup(char* a) const
{

	int thisName = findWebAddress(a);

	if (thisName == -1)
    {
        cout << a << " not found in current Cache\n";
		return 0;
    }
	else
	{
		cout << "\nIP found: ";
		return list[thisName].getIPAddress();
	}
}

void DNSCache::grow()
{
	maxOpenPages = currentOpenPages + 5;
	DNSRecord* newList = new DNSRecord[maxOpenPages];

	for (int i = 0; i < currentOpenPages; i++)
		newList[i] = list[i];

	delete[] list;
	list = newList;
}

DNSCache::DNSCache()
{
	maxOpenPages = 5;
	currentOpenPages = 0;
	list = new DNSRecord[maxOpenPages];
}

DNSCache::~DNSCache()
{
	delete[] list;
}

void DNSCache::add(DNSRecord& a)
{
    ++currentOpenPages;
    list[currentOpenPages] = a;
}

void DNSCache::flush()
{
    while(currentOpenPages!=0)
    {
        currentOpenPages--;
    }
    delete[] list;
}

void DNSCache::print() const
{
	if (currentOpenPages == 0)
	{
		cout << "No Open Pages!" << endl;
		exit(0);
	}

    for (int i = 0; i <= currentOpenPages; i++)
        cout << list[i];
}
