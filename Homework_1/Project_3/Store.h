#pragma once
#include "Product.h";

class Store
{
private:
	Product * mList;
	int mInventory; //capacity
	int mLast; //number of products


public:
	Store();
	Store(int);
	Store(const Store &);
	Store & operator=(const Store &);
	~Store();

	//add hardcoded product
	void Add(Product);
	//add product with characteristics from the console
	void Add();
	//delete product
	void Delete(Product);
	//set the characteristics of the product you would like to delete from the console
	void Delete();
	//write changes from the console
	void Change();
	void Print() const;
};
