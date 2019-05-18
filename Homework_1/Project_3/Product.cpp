#include <iostream>
#include <cstring>
#include "Product.h";

using namespace std;

//default constructor
Product::Product()
{
	mSKU = 0;
	strcpy(mBrand, "Unspecified");
	strcpy(mModel, "Unspecified");
	strcpy(mMaterial, "Unspecified");
	mPrice = 0;
	mSize = 0;
	mCount = 0;
}


//constructor with params
Product::Product(int SKU, char brand[], char model[],
	char material[], double price, int size, int count)
{
	mSKU = SKU;
	strcpy(mBrand, brand);
	strcpy(mModel, model);
	strcpy(mMaterial, material);
	mPrice = price;
	mSize = size;
	mCount = count;
}


void Product::InitFromConsole()
{
	cout << "Set the characteristics of the suit: \n";

	cout << "SKU: ";
	cin >> mSKU;
	cin.ignore();

	cout << "Brand: ";
	cin.getline(mBrand, 20);

	cout << "Model: ";
	cin.getline(mModel, 20);

	cout << "Material: ";
	cin.getline(mMaterial, 20);

	cout << "Price: ";
	cin >> mPrice;

	cout << "Size: ";
	cin >> mSize;

	cout << "Count: ";
	cin >> mCount;
}

//Getters
int Product::GetSKU() const
{
	return mSKU;
}

const char * Product::GetBrand() const
{
	return (char *)mBrand;
}

const char * Product::GetModel() const
{
	return (char *)mModel;
}

const char * Product::GetMaterial() const
{
	return (char *)mMaterial;
}

double Product::GetPrice() const
{
	return mPrice;
}

int Product::GetSize() const
{
	return mSize;
}

int Product::GetCount() const
{
	return mCount;
}

//setters
void Product::SetSKU(int SKU)
{
	mSKU = SKU;
}

void Product::SetBrand(char brand[])
{
	strcpy(mBrand, brand);
}

void Product::SetModel(char model[])
{
	strcpy(mModel, model);
}

void Product::SetMaterial(char material[])
{
	strcpy(mMaterial, material);
}

void Product::SetPrice(double price)
{
	mPrice = price;
}

void Product::SetSize(int size)
{
	mSize = size;
}

void Product::SetCount(int count)
{
	mCount = count;
}


void Product::Print() const
{
	cout << "SKU: " << mSKU << endl;
	cout << "Brand: " << mBrand << endl;
	cout << "Model: " << mModel << endl;
	cout << "Material: " << mMaterial << endl;
	cout << "Price: " << mPrice <<" USD"<< endl;
	cout << "Size: " << mSize << endl;
	cout << mCount << " item(s) in stock. \n";
}
