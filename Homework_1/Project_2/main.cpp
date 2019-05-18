#include <iostream>
#include <cstring>
#include <cstdlib>

#include "DNSCache.h"

using namespace std;

int main()
{
    DNSRecord page;

    page.setDomainName();
    page.setIPAddress();

    DNSRecord page2;
    page2.setDomainName();
    page2.setIPAddress();

    DNSRecord pageTEST("abv.bg", "620.00");
    DNSRecord pageTEST1("abv1.bg", "620.003");

    cout << endl;

    page.printRecord();
    page2.printRecord();
    pageTEST.printRecord();

    DNSCache testing;
    testing.add(page);
    testing.add(page2);
    testing.add(pageTEST);
    testing.add(pageTEST1);

    testing.print();

    cout << testing.lookup("abv1.bg") << endl;

    testing.flush();

    testing.print();

    return 0;
}
