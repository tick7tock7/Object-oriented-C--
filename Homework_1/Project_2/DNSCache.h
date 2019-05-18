#include <iostream>
#include <cstring>
#include <cstdlib>

#include "DNSRecord.h"

using namespace std;

class DNSCache {
private:
    int maxOpenPages;
    int currentOpenPages;

    DNSRecord* list;
    void grow();
    int findWebAddress(char* DomainName) const;

public:
    DNSCache();
    ~DNSCache();
    DNSCache& operator=(DNSCache const &);

    void add(DNSRecord& a);
    const char* lookup(char* a) const;
    void flush();
    void print() const;
};
