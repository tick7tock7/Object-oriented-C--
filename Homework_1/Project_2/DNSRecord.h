#include <iostream>

using namespace std;

const int MAX = 100;

class DNSRecord {
    friend istream& operator >> (istream& a, DNSRecord& page);
	friend ostream& operator << (ostream& a, const DNSRecord& e);

private:
    char domainName[MAX];
    char ipAddress[MAX];

public:
    DNSRecord();
    DNSRecord(char* a, char* b);
    ~DNSRecord();

    void setDomainName();
    void setIPAddress();
    const char* getDomainName() const;
    const char* getIPAddress() const;
    void printRecord() const;
};
