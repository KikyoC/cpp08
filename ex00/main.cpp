#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> ar;

	ar.push_back(2);
	ar.push_back(4);
	ar.push_back(6);
	ar.push_back(10);
	ar.push_back(8);
	std::cout << easyfind(ar, 1) << std::endl;
}
