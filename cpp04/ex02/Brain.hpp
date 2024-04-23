#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

# define NB_IDEAS 100

class Brain
{

private:
	std::string ideas[NB_IDEAS];

public:
	Brain();
	Brain(const Brain &other);
	~Brain();

	Brain &operator=(const Brain &other);

};

#endif
