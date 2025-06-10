#pragma once

#include <stack>
template <typename T>

class MutantStack: public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>()
		{};
		MutantStack(const MutantStack &cpy): std::stack<T>(cpy)
		{};
		MutantStack &operator=(const MutantStack &cpy)
		{
			if (this != &cpy)
				std::stack<T>::operator=(cpy);
			return *this;
		}
		~MutantStack(){};
	
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{
			return std::stack<T>::c.begin();
		};
		iterator end()
		{
			return std::stack<T>::c.end();
		}
		void push(T e)
		{
			std::stack<T>::c.push(e);
		}
};
