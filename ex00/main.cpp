#include <iostream>
#include <vector>
template <typename T>

int easyfind(T &container, int toFind)
{
	for (int i = 0; container[i]; i++)
		if (container[i] == toFind)
			return i;
	return (-1);
}

int main()
{
	std::vector<int> ar;

	ar.push_back(2);
	ar.push_back(4);
	ar.push_back(6);
	ar.push_back(10);
	ar.push_back(8);
	std::cout << easyfind(ar, 8) << std::endl;
}
