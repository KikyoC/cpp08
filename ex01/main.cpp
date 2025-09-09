#include "Span.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>

int main()
// int main(int argc, char **argv)
{
	// Span sp = Span(argc);
	// Span sp = Span(argc - 2);
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	// std::vector<int> lst;
	// while (argc > 1)
	// {
	// 	argc--;
	// 	lst.push_back(std::atoi(argv[argc]));
	// }
	// try
	// {
	// 	sp.addNumber(lst);
	// }
	// catch(std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
