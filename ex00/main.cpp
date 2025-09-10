#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main()
{
	{
		std::vector<int> ar;

		ar.push_back(2);
		ar.push_back(4);
		ar.push_back(6);
		ar.push_back(10);
		ar.push_back(8);
		ar.push_back(1);
		const std::vector<int> constAr = ar;
		std::cout << *easyfind(constAr, 1) << std::endl;
	}
	{
		std::vector<int> ar;

		ar.push_back(2);
		ar.push_back(4);
		ar.push_back(6);
		ar.push_back(10);
		ar.push_back(8);
		ar.push_back(1);
		std::cout << *easyfind(ar, 1) << std::endl;
	}
	{
		std::vector<int> ar;
		ar.push_back(1);
		ar.push_back(2);
		ar.push_back(4);
		ar.push_back(6);
		ar.push_back(10);
		ar.push_back(8);
		std::cout << *easyfind(ar, 1) << std::endl;
	}
	{
		std::list<int> ar;
		ar.push_back(2);
		ar.push_back(4);
		ar.push_back(6);
		ar.push_back(10);
		ar.push_back(8);
		try
		{
			std::cout << *easyfind(ar, 1) << std::endl;
		}
		catch (std::exception &ignored)
		{
			std::cerr << "Not in array" << std::endl;
		}
	}
}
