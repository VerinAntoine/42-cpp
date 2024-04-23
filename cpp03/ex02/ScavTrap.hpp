#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{

public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();

	void attack(const std::string &target);
	void guardGate();

	ScavTrap &operator=(const ScavTrap &other);

};

#endif