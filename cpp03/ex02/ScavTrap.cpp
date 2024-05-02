#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " has been created" << std::endl;
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other.name)
{
	std::cout << "ScavTrap " << name << " has been copied!" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destructed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << name << " attacks " << target
		<< " causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " guard gate!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->name = other.name;
	this->hit_point = other.hit_point;
	this->energy_point = other.energy_point;
	this->attack_damage = other.attack_damage;
	std::cout << "ScavTrap " << name << " has been assigned!" << std::endl;
	return *this;
}
