/*
* ContactList.h
*/

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"

class ContactList
{
public:
	// конструктор
	ContactList();
	// деструктор
	~ContactList();

	void insert();				// вмъква контакт в списъка
	void lookup() const;		// търси име в списъка с контакти
	void remove();				// изтрива контакт
	void update();				// обновява контакт
	void display() const;		// извежда списъка с контакти

private:
	int	maxSize,			// максимум брой контакти
		currentSize;		// текущ брой контакти
	Contact* list;			// указател към динамичен масив с контакти
	void grow();			// увеличава maxSize когато е необходимо
	int findName(char* aName) const;	// връща индекса на кантакт по зададено  име
};

#endif