#include "Dog.hpp"
#include <typeinfo>

Dog::Dog(): Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other): Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	*this = other;
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "BARK" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
	if (this == &other)
		return *this;
	delete this->brain;
	this->brain = new Brain(*other.brain);
	return *this;
}

Dog &Dog::operator=(const Animal &other)
{
	if (typeid(*this) == typeid(other))
		return Dog::operator=((Dog &) other);
	return *this;
}
