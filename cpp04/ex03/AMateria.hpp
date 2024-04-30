#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{

protected:
	std::string type;

public:
	AMateria(std::string const &type);
	virtual ~AMateria() = 0;

	std::string const &getType();

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);

};

#endif
