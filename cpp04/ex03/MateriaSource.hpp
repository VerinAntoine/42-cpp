#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define KNOWN_SIZE 4

class MateriaSource: public IMateriaSource
{

private:
	AMateria *known[KNOWN_SIZE];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

	MateriaSource &operator=(const MateriaSource &other);

};

#endif
