#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <cstddef>

class Span
{

private:
	size_t length;
	std::vector<int> content;

public:
	Span(unsigned int n);
	Span(const Span &other);
	~Span();

	void addNumber(int n);

	int shortestSpan() const;
	int longestSpan() const;
	void fill();

	Span &operator=(const Span &other);

	class FullException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class EmptyException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

};

#endif
