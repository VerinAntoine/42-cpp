#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {

private:
	std::string _name;

public:
	Zombie();
	Zombie(std::string &name);

	void announce(void);
	void setName(std::string &name);

};

Zombie *zombieHorde(int n, std::string name);

#endif
