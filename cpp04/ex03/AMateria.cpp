#include "AMateria.hpp"

AMateria::AMateria(const std::string &type): type(type)
{ }

AMateria::~AMateria()
{ }

std::string const &AMateria::getType()
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}
