/*
* Contact.cpp
*/

#include <string>			// �� strlen, strcpy_s
#include "Contact.h"


//---------- ������������� �� ��������� ---------

istream& operator >> (istream& s, Contact& c)
// ������ �� ����� ���� ������������� �� ��������� >>
{
	s.getline(c.name, 20);		    // Gets a name; discards newline.
	s.getline(c.phoneNumber, 20);	// Gets a phone; discards newline.
	s.getline(c.address, 20);		// Gets an address; discards newline.

	return s;
}

ostream& operator << (ostream& s, const Contact& c)
// ������� Contact ���� ��������������� �������� <<
{
	int i;

	s << '\t' << c.name;		// ������� name (���� tab).
								// ������� ���������
	for (i = strlen(c.name) + 1; i < 20; i++)
		s.put(' ');

	s << '\t' << c.phoneNumber;		// ������� ��������� �����
	for (i = strlen(c.phoneNumber) + 1; i < 20; i++)
		s.put(' ');

	s << '\t' << c.address;			// ������� �����
	s << '\n';

	return s;
}

// ����������
Contact::Contact()
{
	strcpy_s(name, " ");
	strcpy_s(phoneNumber, " ");
	strcpy_s(address, " ");
}

//---------- ������ ----------


const char* Contact::getName() const
{
	return name;
}
