#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Jamie");
	zombie->announce();
	delete zombie;

	randomChump("Bob");

	return 0;
}
