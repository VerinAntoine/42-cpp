#include "Zombie.hpp"

#define N 5
#define NAME "bob"

int main()
{
	Zombie *zombies = zombieHorde(N, NAME);

	for (int i = 0; i < N; i++)
		zombies[i].announce();
	
	delete [] zombies;
	return 0;
}
