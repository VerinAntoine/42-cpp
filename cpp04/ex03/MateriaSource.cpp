#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < KNOWN_SIZE; i++)
		known[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < KNOWN_SIZE; i++)
	{
		if (known[i] != NULL)
			delete known[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < KNOWN_SIZE; i++)
	{
		if (known[i] == NULL)
		{
			known[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < KNOWN_SIZE; i++)
	{
		if (known[i] != NULL && known[i]->getType() == type)
			return known[i]->clone();
	}
	return 0;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < KNOWN_SIZE; i++)
	{
		if (known[i] != NULL)
			delete known[i];
		known[i] = other.known[i]->clone();
	}
	return *this;
}
