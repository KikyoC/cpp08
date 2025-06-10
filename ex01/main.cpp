#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);

	std::vector<int> lst;
	lst.push_back(6);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(9);
	lst.push_back(11);


	sp.addNumber(lst);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
