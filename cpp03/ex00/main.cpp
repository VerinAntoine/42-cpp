#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("bob");

	a.attack("mich");
	a.takeDamage(5);
	a.beRepaired(10);
	ClapTrap b(a);
	b.takeDamage(10);
	b.takeDamage(10);
	b.attack("jean");
	return 0;
}
