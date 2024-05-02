#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name): name(name)
{
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 10;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap " << name << " has been copied!" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destructed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!energy_point)
		return;
	energy_point--;
	std::cout << "ClapTrap " << name << " attacks " << target
		<< " causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hit_point)
		hit_point = 0;
	else
		hit_point -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount
		<< " points of damage! (" << hit_point << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energy_point)
		return;
	energy_point--;
	hit_point += amount;
	std::cout << "ClapTrap " << name << " has been repaired of " << amount
		<< " points! (" << hit_point << ")" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->name = other.name;
	this->hit_point = other.hit_point;
	this->energy_point = other.energy_point;
	this->attack_damage = other.attack_damage;
	std::cout << "ClapTrap " << name << " has been assigned!" << std::endl;
	return *this;
}
