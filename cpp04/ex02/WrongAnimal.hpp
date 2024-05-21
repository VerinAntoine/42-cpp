#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{

protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();

	void makeSound();

	std::string getType() const;

	WrongAnimal &operator=(const WrongAnimal &other);

};

#endif
