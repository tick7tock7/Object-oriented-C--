#include<iostream>
#include<cstring>

#include "DNSRecord.h"

DNSRecord::DNSRecord()
{
    strcpy(domainName, " ");
    strcpy(ipAddress, " ");
}

DNSRecord::DNSRecord(char* a, char* b)
{
    strcpy(domainName, a);
    strcpy(ipAddress, b);
}

DNSRecord::~DNSRecord()
{
    delete[] domainName;
    delete[] ipAddress;
}

void DNSRecord::setDomainName()
{
    cin.getline(domainName, MAX);
}

void DNSRecord::setIPAddress()
{
    cin.getline(ipAddress, MAX);
}

const char* DNSRecord::getDomainName() const
{
    return domainName;
}

const char* DNSRecord::getIPAddress() const
{
    return ipAddress;
}

void DNSRecord::printRecord() const
{
    cout << domainName << endl;
    cout << ipAddress << endl;
}

istream& operator >> (istream& s, DNSRecord& page)
{
    s.getline(page.domainName, 100);
    s.getline(page.ipAddress, 100);

    return s;
}

ostream& operator << (ostream& s, const DNSRecord& page)
{
    int i;

    s << page.domainName;

    cout << endl;

    s << page.ipAddress;

    cout << endl;

    return s;
}
