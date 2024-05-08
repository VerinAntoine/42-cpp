#include "Animal.hpp"

Animal::Animal()
{
	this->type = "";
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal copied" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal desctructed" << std::endl;
}

void Animal::makeSound() { }

std::string Animal::getType() const
{
	return this->type;
}

Animal &Animal::operator=(const Animal &other)
{
	(void) other;
	return *this;
}
