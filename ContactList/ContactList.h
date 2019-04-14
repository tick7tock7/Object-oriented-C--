/*
* ContactList.h
*/

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"

class ContactList
{
public:
	// �����������
	ContactList();
	// ����������
	~ContactList();

	void insert();				// ������ ������� � �������
	void lookup() const;		// ����� ��� � ������� � ��������
	void remove();				// ������� �������
	void update();				// �������� �������
	void display() const;		// ������� ������� � ��������

private:
	int	maxSize,			// �������� ���� ��������
		currentSize;		// ����� ���� ��������
	Contact* list;			// �������� ��� ��������� ����� � ��������
	void grow();			// ��������� maxSize ������ � ����������
	int findName(char* aName) const;	// ����� ������� �� ������� �� ��������  ���
};

#endif