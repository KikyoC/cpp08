#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span(unsigned int N): max(N), actual(0)
{}

Span::Span(const Span &cpy): max(cpy.max), actual(cpy.actual)
{
	for (unsigned long i = 0; i < this->actual; i++)
		this->stored[i] = cpy.stored[i];
}

Span &Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		this->max = cpy.max;
		this->actual = cpy.actual;
		for (unsigned long i = 0; i < this->actual; i++)
			this->stored[i] = cpy.stored[i];
	}
	return *this;
}

Span::~Span()
{
}

const char *Span::SpanFullException::what() const throw()
{
	return "Error: Index out of bound exception";
}

const char *Span::ToFewElementsException::what() const throw()
{
	return "Error: There is not enough stored elements to perform this action";
}


void Span::addNumber(int i)
{
	if (this->stored.size() >= this->max)
		throw SpanFullException();
	this->stored.push_back(i);
}

void Span::addNumber(std::vector<int> lst)
{
	for (unsigned int i = 0; i < lst.size(); i++)
		this->addNumber(lst[i]);
}

int Span::shortestSpan() const
{
	int minimum;

	std::vector<int> tmp = this->stored;
	if (this->stored.size() <= 1)
		throw ToFewElementsException();
	std::sort(tmp.begin(), tmp.end());
	minimum = tmp[1] - tmp[0];
	for (unsigned long i = 2; this->stored.size() > i; i++)
		if (tmp[i] - tmp[i - 1] < minimum)
			minimum = tmp[i] - tmp[i - 1];
	return (minimum);
}

int Span::longestSpan() const
{
	std::vector<int> tmp = this->stored;
	if (this->stored.size() <= 1)
		throw ToFewElementsException();
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}
