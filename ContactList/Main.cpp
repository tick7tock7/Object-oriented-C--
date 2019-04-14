#include <cctype>			// �� toupper
#include <iostream>			// �� cin, cout
#include "ContactList.h"	

using namespace std;

void showMenu()
// ������� �������� ���� �� ����������
{
	cout << "\n\t\t*** CONTACT LIST ***";
	cout << "\n\tI \tInsert a new contact";
	cout << "\n\tL \tLook up a contact";
	cout << "\n\tR \tRemove a contact";
	cout << "\n\tU \tUpdate a contact";
	cout << "\n\tD \tDisplay the entire contact list";
	cout << "\n\t? \tDisplay this menu";
	cout << "\n\tQ \tQuit";
}

char getAChar(char* promptString)
// ���� ����������� � ������� ����,
// ���� �������� ����� �� ��� ���.
// �������� �� � GetCommand.
{
	char response;

	cout << promptString;
	cin >> response;				// ��������� ����,
	response = toupper(response);	// � �� ������������ � ������ �����
	cin.get();						// ���������� ����� �� ��� ��� �� �����
	return response;
}

bool legal(char c)
// �������� ���� ������, c, ����������� �� ������� ������� �� ������
// �������� �� �� getCommand.
{
	return	((c == 'I') || (c == 'L') || (c == 'R') || (c == 'U') ||
		(c == 'D') || (c == '?') || (c == 'Q'));
}

char getCommand()
{
	char cmd = getAChar("\n\n>");	// ������� ���� �� �������.

	while (!legal(cmd))		// ��� �� � ��������� �������,
	{						// ������� ������ � ���� ������.
		cout << "\nIllegal command, please try again . . .";
		showMenu();
		cmd = getAChar("\n\n>");
	}
	return cmd;
}

int main()
{
	ContactList l;			// ��������� � �������������� ������ � ��������.

	showMenu();				// ��������� ������

	char command;
	do
	{
		command = getCommand();		// ��������� �������
		switch (command)
		{
			case 'I': l.insert();				break;
			case 'L': l.lookup();				break;
			case 'R': l.remove();				break;
			case 'U': l.update();				break;
			case 'D': l.display();				break;
			case '?': showMenu();				break;
			case 'Q':							break;
		}
	} while (command != 'Q');

	return 0;
}