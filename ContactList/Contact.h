/*
* Contact.h
*/

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>		// �� �� ������������� << � >>

using namespace std;


class Contact
{
	friend istream& operator >> (istream& a, Contact& e);
	friend ostream& operator << (ostream& a, const Contact& e);

public:
	// �����������
	Contact();
	// ������� �� ������
	const char* getName() const;		// ����� ����� �� ��������

private:
	char name[20];			// ��� (20 �����)
	char phoneNumber[20];	// ��������� ����� (20 �����)
	char address[20];		// ����� (20 �����)
};

#endif 