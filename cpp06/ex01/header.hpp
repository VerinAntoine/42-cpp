#ifndef HEADER_HPP
# define HEADER_HPP

# include <string>
# include <stdint.h>

struct Data
{
	std::string name;
	int value;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
