#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{

protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() = 0;

	std::string getType() const;

	Animal &operator=(const Animal &other);

};

#endif
