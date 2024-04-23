#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other): Animal()
{
	*this = other;
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "BARK" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
	(void) other;
	return *this;
}
