#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other.name)
{
	std::cout << "FragTrap " << name << " has been copied!" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destructed!" << std::endl;
}

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << name << " ask to high five the guys!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	this->name = other.name;
	this->hit_point = other.hit_point;
	this->energy_point = other.energy_point;
	this->attack_damage = other.attack_damage;
	std::cout << "FragTrap " << name << " has been assigned!" << std::endl;
	return *this;
}
