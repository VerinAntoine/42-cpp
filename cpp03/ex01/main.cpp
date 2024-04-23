#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("mich");

	a.attack("bob");
	a.beRepaired(5);
	a.guardGate();
	
	return 0;
}
