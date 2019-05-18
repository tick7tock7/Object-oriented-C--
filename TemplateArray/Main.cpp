#include <iostream>
#include "MyArray.h"


int main()
{
	MyArray<int> t1(5);
	for (int i = 0; i < t1.size(); i++)
		std::cout << ' ' << t1[i];
	std::cout << '\n';

	MyArray<int> t2(5, 100);
	for (int i = 0; i < t2.size(); i++)
		std::cout << ' ' << t2[i];
	std::cout << '\n';

	MyArray<double> d;
	for (int i = 0; i < 100; i++) {
		d.push_back((double)i);
		std::cout << "item: " << d[i] << '\n';
		std::cout << "size: " << d.size() << '\n';
		std::cout << "capacity: " << d.capacity() << '\n';
	}

	MyArray<double> d1(d);
	std::cout << "size: " << d1.size() << '\n';
	std::cout << "capacity: " << d1.capacity() << '\n';
	while (!d1.empty()) {
		std::cout << "item: " << d1[d1.size() - 1] << '\n';
		d1.pop_back();
	}
	std::cout << "size: " << d1.size() << '\n';
	std::cout << "capacity: " << d1.capacity() << '\n';

	return 0;
}