/*
* ContactList.cpp
*/

#include <iostream>
#include <string>			// �� strcmp
#include "ContactList.h"

using namespace std;

ContactList::ContactList()
{
	maxSize = 5;
	currentSize = 0;
	list = new Contact[maxSize];
}

ContactList::~ContactList()
{
	delete[] list;
}

void ContactList::insert()
{
	if (currentSize == maxSize)		// ��� �������� � �����, ������ ������� grow
		grow();

	cout << "\nType the name, phone number, and address, each followed"
		<< "\n by RETURN or ENTER:\n> ";

	cin >> list[currentSize++];	// ������� ��� �������
}

void ContactList::lookup() const
//  ������� ������� �� �������� ���
{
	char aName[20];
	cout << "\tType the name to be looked up, followed by <Enter>: ";
	cin.getline(aName, 20);

	int thisContact = findName(aName);

	if (thisContact == -1)
		cout << aName << " not found in current contact list\n";
	else
	{
		cout << "\nContact found: ";
		cout << list[thisContact];	
	}
}

void ContactList::remove()
{
	// Prompt the user for the name to be removed.
	char aName[20];
	cout << "\nType name to be removed, followed by <Enter>: ";
	cin.getline(aName, 20);

	int thisContact = findName(aName);

	if (thisContact == -1)
		cout << aName << " not found in contact list";
	else
	{
		for (int j = thisContact + 1; j < currentSize; j++)
			list[j - 1] = list[j];

		currentSize--;
		cout << "Contact removed.\n";
	}
}

void ContactList::update()
{
	cout << "\nPlease enter the name of the contact to be modified: ";
	char aName[20];
	cin.getline(aName, 20);

	int thisContact = findName(aName);

	if (thisContact == -1)
		cout << aName << " not found in current contact list\n";
	else
	{
		cout << "\nCurrent contact is: \n";
		cout << list[thisContact];

		cout << "\nReplace with new entries as follows: \n";
		cin >> list[thisContact];		// ��������� �� ���� ��������� �� ��������
	}
}

void ContactList::display() const
{
	if (currentSize == 0)
	{
		cout << "\nCurrent contact list is empty.\n";
		return;
	}

	// Display a header.
	cout << "\n\t***NAME***\t\t***PHONE***\t\t***ADDRESS***\n\n";

	for (int i = 0; i < currentSize; i++)
		cout << list[i];
}

void ContactList::grow()
{
	maxSize = currentSize + 5;				// ���������� �� ����� ������.
	Contact* newList = new Contact[maxSize];		// ��������� �� ��� �����.

	for (int i = 0; i < currentSize; i++)	// �������� � ����� �����
		newList[i] = list[i];

	delete[] list;
	list = newList;
}

int ContactList::findName(char* aName) const
{
	for (int i = 0; i < currentSize; i++)
		if (strcmp(list[i].getName(), aName) == 0)
			return i;		// return i ��� � ��������

	return -1;				// return -1 ��� �� � ��������
}
