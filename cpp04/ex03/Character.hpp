#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

# define SLOT_SIZE 4

class Character: public ICharacter
{

private:
	std::string name;
	AMateria *slots[SLOT_SIZE];

public:
	Character(const std::string &name);
	Character(const Character &other);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	Character &operator=(const Character &other);

};

#endif
