#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>

Span::Span(unsigned int n): length(n)
{
	content.reserve(n);
}

Span::Span(const Span &other): length(other.length)
{
	content.reserve(length);
	for (size_t i = 0; i < other.content.size(); i++)
		content.push_back(other.content[i]);
}

Span::~Span()
{ }

void Span::addNumber(int n)
{
	if (content.size() == length)
		throw FullException();
	content.push_back(n);
}

int Span::shortestSpan() const
{
	std::cout << content.size() << std::endl;
	if (content.size() < 2)
		throw EmptyException();
	
	int shortest = -1;
	for (std::vector<int>::const_iterator i = content.begin() + 1; i != content.end(); i++)
	{
		int s = std::abs(*(i - 1) - *i);
		if (s < shortest || shortest == -1)
			shortest = s;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (content.size() < 2)
		throw EmptyException();

	return *std::max_element(content.begin(), content.end()) - *std::min_element(content.begin(), content.end());
}

void Span::fill() {
	content.resize(length);
    std::srand((unsigned) time(NULL));
    std::generate(content.begin(), content.end(), std::rand);
}

Span &Span::operator=(const Span &other)
{
	length = other.length;
	content.reserve(length);
	for (size_t i = 0; i < other.content.size(); i++)
		content.push_back(other.content[i]);
	return *this;
}

const char *Span::FullException::what() const throw()
{
	return "span is full";
}

const char *Span::EmptyException::what() const throw()
{
	return "span is empty";
}
