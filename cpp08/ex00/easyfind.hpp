#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

class NotFoundException: public std::exception
{
public:
	virtual const char *what() const throw();
};

template<typename T>
void easyfind(T &container, int n)
{
	if(*(std::find(container.begin(), container.end(), n)) != n)
		throw NotFoundException();
	else
		std::cout << "found!" << std::endl;
}

#endif
