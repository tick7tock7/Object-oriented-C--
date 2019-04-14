#include <cctype>			// за toupper
#include <iostream>			// за cin, cout
#include "ContactList.h"	

using namespace std;

void showMenu()
// извежда главното меню на програмата
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
// пита потребителя и прочита знак,
// като изключва знака за нов ред.
// Използва се в GetCommand.
{
	char response;

	cout << promptString;
	cin >> response;				// прочитаме знак,
	response = toupper(response);	// и го преобрзуваме в главна буква
	cin.get();						// изчистваме знака за нов ред от входа
	return response;
}

bool legal(char c)
// определя дали знакът, c, съответства на легална команда от менюто
// използва се от getCommand.
{
	return	((c == 'I') || (c == 'L') || (c == 'R') || (c == 'U') ||
		(c == 'D') || (c == '?') || (c == 'Q'));
}

char getCommand()
{
	char cmd = getAChar("\n\n>");	// прочита знак за команда.

	while (!legal(cmd))		// ако не е допустима команда,
	{						// извежда менюто и пита отнова.
		cout << "\nIllegal command, please try again . . .";
		showMenu();
		cmd = getAChar("\n\n>");
	}
	return cmd;
}

int main()
{
	ContactList l;			// създаваме и инициализирами списък с контакти.

	showMenu();				// извеждаме менюто

	char command;
	do
	{
		command = getCommand();		// извличаме команда
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