#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	for (int i = 0; i < NB_IDEAS; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}
