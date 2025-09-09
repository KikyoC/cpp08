#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <vector>

Span::Span(): max(10), actual(0) {}

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

const char *Span::OverflowException::what() const throw()
{
	return "Error: The value overflow. Is not possible to convert";
}

void Span::addNumber(int i)
{
	if (this->stored.size() >= this->max)
		throw SpanFullException();
	this->stored.push_back(i);
}

void Span::addNumber(std::vector<int> lst)
{
	if (lst.size() + this->stored.size() >= this->max)
		throw SpanFullException();
	for (unsigned int i = 0; i < lst.size(); i++)
		this->addNumber(lst[i]);
}

int Span::shortestSpan() const
{
	long long minimum;

	std::vector<int> tmp = this->stored;
	if (this->stored.size() <= 1)
		throw ToFewElementsException();
	std::sort(tmp.begin(), tmp.end());
	minimum = static_cast<long long>(tmp[1]) - static_cast<long long>(tmp[0]);
	for (unsigned long i = 1; this->stored.size() > i; i++)
		if (tmp[i] - tmp[i - 1] < minimum)
			minimum = static_cast<long long>(tmp[1]) - static_cast<long long>(tmp[0]);
	if (minimum < std::numeric_limits<int>::min() || minimum > std::numeric_limits<int>::max())
		throw OverflowException();
	return (minimum);
}

int Span::longestSpan() const
{
	long long maximum;
	std::vector<int> tmp = this->stored;
	if (this->stored.size() <= 1)
		throw ToFewElementsException();
	std::sort(tmp.begin(), tmp.end());
	maximum = static_cast<long long>(tmp[tmp.size() - 1]) - static_cast<long long>(tmp[0]);
	if (maximum < std::numeric_limits<int>::min() || maximum > std::numeric_limits<int>::max())
		throw OverflowException();
	return (maximum);
}
