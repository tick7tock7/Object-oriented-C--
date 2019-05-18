#include <iostream>
#include <cstring>
#include "Store.h";

using namespace std;

//default constructor
Store::Store()
{
	mInventory = 1;
	mLast = -1;
	mList = new Product[mInventory];
}

//constructor with parameter
Store::Store(int inventory)
{
	mInventory = inventory;
	mLast = -1;
	mList = new Product[mInventory];
}

//copy constructor
Store::Store(const Store & rhs)
{
	mInventory = rhs.mInventory;
	mLast = rhs.mLast;
	mList = new Product[mInventory];
	for (int i = 0; i < mLast+1; i++)
	{
		mList[i] = rhs.mList[i];
	}
}

//operator overload
Store & Store::operator=(const Store & rhs)
{
	if (this!=&rhs)
	{
		delete[] mList;

		mInventory = rhs.mInventory;
		mLast = rhs.mLast;
		mList = new Product[mInventory];
		for (int i = 0; i < mLast+1; i++)
		{
			mList[i] = rhs.mList[i];
		}
	}
	return *this;
}

//destructor
Store::~Store()
{
	delete[] mList;
}


//hardcode add
void Store::Add(Product token)
{
	if (mInventory-1==mLast)
	{
		cout << "Store is full." << endl;
	}
	else
	{
		for (int i = 0; i < mInventory; i++)
		{
			if (token.GetSKU() == mList[i].GetSKU())
			{
				cout << "A product with SKU " << token.GetSKU() << "already exists. \n";
				return;
			}
		}


		mLast++;
		mList[mLast] = token;
	}
}

//add from console
void Store::Add()
{
	if (mInventory-1==mLast)
	{
		cout << "Store is full." << endl;
	}
	else
	{
		Product newProduct;
		newProduct.InitFromConsole();

		for (int i = 0; i < mInventory; i++)
		{
			if (newProduct.GetSKU() == mList[i].GetSKU())
			{
				cout << "A product with SKU " << newProduct.GetSKU() << "already exists. \n";
				return;
			}
		}

		mLast++;
		mList[mLast]=newProduct;
	}
}

void Store::Delete()
{
	if (mLast==-1)
	{
		cout << "Inventory is empty. \n";
	}
	else
	{
		std::cout << "Enter the SKU of the T-Shirt you would like to remove from inventory: ";
		int deleteSKU;
		cin >> deleteSKU;
		bool matchFound = false;
		char DEFAULT[20] = "Unspecified";

		for (int i = 0; i < mLast + 1; i++)
		{
			if (mList[i].GetSKU() == deleteSKU)
			{
				mList[i].SetSKU(0);
				mList[i].SetBrand(DEFAULT);
				mList[i].SetModel(DEFAULT);
				mList[i].SetMaterial(DEFAULT);
				mList[i].SetPrice(0);
				mList[i].SetSize(0);
				mList[i].SetCount(0);

				//shift
				for (int j = i; j < mLast; j++)
				{
					mList[j] = mList[j + 1];
				}
				mList[mLast] = mList[i];
				mLast--;
				matchFound = true;
				break;
			}
		}
		if (!matchFound)
		{
			cout << "No such item was found in inventory!" << endl;
		}
	}
}

void Store::Delete(Product token)
{
	if (mLast==-1)
	{
		std::cout << "Inventory is empty. \n";
	}
	else
	{
		//char DEFAULT[20] = "Unspecified";
		bool matchFound = false;

		for (int i = 0; i < mLast + 1; i++)
		{
			if (mList[i].GetSKU() == token.GetSKU() &&
				strcmp(mList[i].GetBrand(), token.GetBrand()) == 0 &&
				strcmp(mList[i].GetModel(), token.GetModel()) == 0 &&
				strcmp(mList[i].GetMaterial(), token.GetMaterial()) == 0 &&
				mList[i].GetPrice() == token.GetPrice() &&
				mList[i].GetSize() == token.GetSize() &&
				mList[i].GetCount() == token.GetCount())
			{
				/*
				mList[i].SetSKU(0);
				mList[i].SetBrand(DEFAULT);
				mList[i].SetModel(DEFAULT);
				mList[i].SetMaterial(DEFAULT);
				mList[i].SetPrice(0);
				mList[i].SetSize(0);
				*/

				//shift
				for (int j = i; j < mLast; j++)
				{
					mList[j] = mList[j + 1];
				}
				mList[mLast] = mList[i];
				mLast--;
			}
		}
		if (!matchFound)
		{
			std::cout << "No such item was found in inventory!" << std::endl;
		}
	}
}

void Store::Change()
{
    cout << "Enter the SKU of the T-Shirt you would like to change: ";
	int changeSKU;
    cin >> changeSKU;
	bool matchFound = false;

	for (int i = 0; i < mLast + 1; i++)
	{
		if (mList[i].GetSKU() == changeSKU)
		{
			Product temp;
			temp.InitFromConsole();

			for (int j = 0; j < mLast+1; j++)
			{
				if (temp.GetSKU() == mList[j].GetSKU())
				{
					cout << "A product with that SKU already exists. \n";
					return;
				}
			}

			mList[i]=temp;
			matchFound = true;
			break;
		}
	}
	if (!matchFound)
	{
		cout << "No such item was found in inventory!" << endl;
	}
}


void Store::Print() const
{

	cout << mLast+1 << " product(s) in inventory right now: " << endl;
	for (int i = 0; i < mLast +1; i++)
	{
		mList[i].Print();
		cout << endl;
	}
}
