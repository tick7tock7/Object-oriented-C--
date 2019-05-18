#include <iostream>
#include <cctype>

#include "Store.h";

using namespace std;

void ToggleMenu(Store selected);

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
	Store alpha(10);
	alpha.Add(one);
	alpha.Add(two);

	cout << "Menu: \n";
	cout << "Press A to add new product. \n";
	cout << "Press X to delete product. \n";
	cout << "Press C to change product. \n";
	cout << "Press D to display products. \n";
	cout << "Press Q to add item to quit. \n\n";

	cout << "Initial state of store: \n";
	alpha.Print();
	cout << endl;

	ToggleMenu(alpha);

	return 0;
}

void ToggleMenu(Store selected)
{
	//menu
	cout << "Please choose a command from the menu: ";W

	char option;
	cin >> option;
	switch (option)
	{
	case 'A':
		selected.Add();
		cout << "Command complete! \n\n";
		break;
	case 'X':
		selected.Delete();
		cout << "Command complete! \n\n";
		break;
	case 'C':
		selected.Change();
		cout << "Command complete! \n\n";
		break;
	case 'D':
		selected.Print();
		cout << "Command complete! \n\n";
		break;
	case 'Q':
		cout << "Command complete! \n\n";
		return;
	default:
		cout << "Invalid option. \n\n";
		break;
	}
	ToggleMenu(selected);
}

