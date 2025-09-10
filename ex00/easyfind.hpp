#pragma once

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::exception();
	return it;
}

template <typename T>
const typename T::const_iterator easyfind(const T &container, int toFind)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::exception();
	return it;
}
