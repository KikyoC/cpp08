#pragma once

#include <exception>
template <typename T>
unsigned int easyfind(T &container, int toFind)
{
	unsigned int i = 0;
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == toFind)
			return i;
		i++;
	}
	throw std::exception();
}
