/*
* Contact.h
*/

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>		// за да предефинираме << и >>

using namespace std;


class Contact
{
	friend istream& operator >> (istream& a, Contact& e);
	friend ostream& operator << (ostream& a, const Contact& e);

public:
	// конструктор
	Contact();
	// функции за достъп
	const char* getName() const;		// връща името на кантакта

private:
	char name[20];			// име (20 знака)
	char phoneNumber[20];	// телефонен номер (20 знака)
	char address[20];		// адрес (20 знака)
};

#endif 