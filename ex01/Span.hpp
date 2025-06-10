#pragma once

# include <vector>
# include <exception>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &cpy);
		Span &operator=(const Span &cpy);
		~Span();

		void addNumber(int i);
		void addNumber(std::vector<int> lst);
		int shortestSpan() const;
		int longestSpan() const;

		class SpanFullException: public std::exception
		{
			virtual const char *what() const throw();
		};

		class ToFewElementsException: public std::exception
		{
			virtual const char *what() const throw();
		};


	private:
		std::vector<int> stored;
		unsigned long max;
		unsigned long actual;
};
