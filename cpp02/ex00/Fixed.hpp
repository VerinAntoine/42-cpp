#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

private:
	static const int bits = 8;
	int value;

public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed &operator=(const Fixed &other);

};

#endif