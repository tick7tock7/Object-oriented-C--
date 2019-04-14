/*
* Contact.cpp
*/

#include <string>			// за strlen, strcpy_s
#include "Contact.h"


//---------- Предефиниране на оператори ---------

istream& operator >> (istream& s, Contact& c)
// четене на данни чрез предефиниране на оператора >>
{
	s.getline(c.name, 20);		    // Gets a name; discards newline.
	s.getline(c.phoneNumber, 20);	// Gets a phone; discards newline.
	s.getline(c.address, 20);		// Gets an address; discards newline.

	return s;
}

ostream& operator << (ostream& s, const Contact& c)
// извежда Contact чрез предефинираания оператор <<
{
	int i;

	s << '\t' << c.name;		// извежда name (след tab).
								// извежда интервали
	for (i = strlen(c.name) + 1; i < 20; i++)
		s.put(' ');

	s << '\t' << c.phoneNumber;		// извежда телефонен номер
	for (i = strlen(c.phoneNumber) + 1; i < 20; i++)
		s.put(' ');

	s << '\t' << c.address;			// извежда адрес
	s << '\n';

	return s;
}

// Консруктор
Contact::Contact()
{
	strcpy_s(name, " ");
	strcpy_s(phoneNumber, " ");
	strcpy_s(address, " ");
}

//---------- Методи ----------


const char* Contact::getName() const
{
	return name;
}
