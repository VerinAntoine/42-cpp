#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "";
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal desctructed" << std::endl;
}

void WrongAnimal::makeSound() { }

std::string WrongAnimal::getType() const
{
	return this->type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	(void) other;
	return *this;
}
