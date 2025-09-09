#pragma once

# include <vector>
# include <exception>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &cpy);
		Span &operator=(const Span &cpy);
		~Span();

		void addNumber(int i);
		void addNumber(std::vector<int> lst);
		template<typename T>
		void addNumber(T begin, T end)
		{
			int i = 0;
			for (T it = begin; it != end; it++)
			{
				i++;
			}
			if (i + this->actual >= this->max)
				throw SpanFullException();
			for (T it = begin; it != end; it++)
			{
				this->addNumber(*it);
			}
		}
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
	
		class OverflowException: public std::exception
		{
			virtual const char *what() const throw();
		};


	private:
		std::vector<int> stored;
		unsigned long max;
		unsigned long actual;
};
