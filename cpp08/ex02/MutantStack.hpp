#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T>
{

public:
	MutantStack() { };
	MutantStack(const MutantStack &other)
	{
		*this = other;
	};
	~MutantStack() { }

	MutantStack &operator=(const MutantStack &other)
	{
		if (*this == other)
			return *this;
		std::stack<T, Container>::operator=(other);
		return *this;
	}

	typedef typename Container::iterator iterator;

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

};

#endif
