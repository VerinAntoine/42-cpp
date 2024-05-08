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

	virtual void makeSound();

	std::string getType() const;

	virtual Animal &operator=(const Animal &other);

};

#endif
