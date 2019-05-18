#pragma once

//T-Shirts

//const int DEFAULT = 0;

class Product
{
private:
	int mSKU; //stock keeping unit
	char mBrand[20]; //e.g. Gucci, Reserved, etc.
	char mModel[20]; //fall/winter, summer/fall or spring/summer
	char mMaterial[20]; //e.g. cotton, silk, etc.
	double mPrice; //in USD
	int mSize; //European standard
	int mCount;

public:
	//constructors
	Product();
	Product(int, char[], char[], char[], double, int, int);

	//set all characteristics from the console
	void InitFromConsole();

	int GetSKU() const;
	const char * GetBrand() const;
	const char * GetModel() const;
	const char * GetMaterial() const;
	double GetPrice() const;
	int GetSize() const;
	int GetCount() const;

	void SetSKU(int);
	void SetBrand(char []);
	void SetModel(char []);
	void SetMaterial(char []);
	void SetPrice(double);
	void SetSize(int);
	void SetCount(int);

	void Print() const;
};
