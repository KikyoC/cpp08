#pragma once

template <typename T>
int easyfind(T &container, int toFind)
{
	for (unsigned long i = 0; i < container.size(); i++)
		if (container[i] == toFind)
			return i;
	return (-1);
}

