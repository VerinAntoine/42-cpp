#include "Dog.hpp"
#include "Cat.hpp"

#define NB_ANIMALS 10

int main()
{
	// Animal *meta = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	return 0;
}
