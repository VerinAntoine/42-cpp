#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <map>

class Harl
{

private:
	std::map<std::string, void (Harl::*)()> levels;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl();
	void complain(std::string level);

};

#endif
