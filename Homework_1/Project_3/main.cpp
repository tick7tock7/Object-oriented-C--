#include <iostream>
#include <cctype>

#include "Store.h";

using namespace std;

void showMenu()
{
	cout << "Store Menu:" << endl;
	cout << "A: Add new product" << endl;
	cout << "X: Delete product" << endl;
	cout << "C: Change product" << endl;
	cout << "D: Display products" << endl;
	cout << "Q: Quit" << endl;
}

char getAChar(char* promptString)
{
	char response;

	cout << promptString;
	cin >> response;
	response = toupper(response);
	cin.get();
	return response;
}

bool legal(char c)
{
	return	((c == 'A') || (c == 'X') || (c == 'C') || (c == 'D') || (c == 'Q'));
}

char getCommand()
{
	char cmd = getAChar("\n\n>");

	while (!legal(cmd))
	{
		cout << "\nIllegal command, please try again . . .";
		showMenu();
		cmd = getAChar("\n\n>");
	}
	return cmd;
}

int main()
{
	//brands
	char Gucci[20] = "Gucci";
	char HM[20] = "H&M";
	char RL[20] = "Polo Ralph Lauren";

	//models/collections
	char ss[20] = "Spring/Summer";
	char fw[20] = "Fall/Winter";

	//materials
	char silk[20] = "Silk";
	char wool[20] = "Wool";
	char cotton[20] = "Cotton";

	Product one(56, Gucci, ss, cotton, 75, 44, 12);
	Product two(15, RL, fw, silk, 100, 46, 4);


	//10 different types of products can be added
	//DOES NOT HAVE ANYTHING TO DO WITH HOW MANY ITEMS OF EACH PRODUCT ARE THERE
	Store Mall(10);
    Mall.Add(one);
    Mall.Add(two);

	cout << "Initial state of store: \n";
	Mall.Print();
	cout << endl;

    showMenu();

    bool choice = true;
	do
	{
	    char command;
		command = getCommand();
		switch (command)
		{
			case 'A': Mall.Add();				break;
			case 'X': Mall.Delete();			break;
			case 'C': Mall.Change();			break;
			case 'D': Mall.Print();				break;
			case 'Q': choice = false;   		break;
		}
	} while (choice);

	return 0;
}
