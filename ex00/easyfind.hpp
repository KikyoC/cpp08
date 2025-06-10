#pragma once

template <typename T>
int easyfind(T &container, int toFind)
{
	for (int i = 0; container[i]; i++)
		if (container[i] == toFind)
			return i;
	return (-1);
}

