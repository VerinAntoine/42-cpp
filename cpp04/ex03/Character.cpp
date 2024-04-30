#include "Character.hpp"

Character::Character(const std::string &name): name(name)
{
	for (int i = 0; i < SLOT_SIZE; i++)
		slots[i] = NULL;
}

Character::Character(const Character &other): name(other.name)
{
	*this = other;
}

Character::~Character()
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slots[i] != NULL)
			delete slots[i];
	}
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= SLOT_SIZE || slots[idx] == NULL)
		return ;
	slots[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= SLOT_SIZE || slots[idx] == NULL)
		return ;
	slots[idx]->use(target);
}

Character &Character::operator=(const Character &other)
{
	if (this == &other)
		return *this;
	this->name = other.name;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slots[i] != NULL)
			delete slots[i];
		slots[i] = other.slots[i]->clone();
	}
	return *this;
}
