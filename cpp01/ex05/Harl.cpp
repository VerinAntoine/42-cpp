#include "Harl.hpp"

Harl::Harl()
{
	levels[0].name = "debug";
	levels[0].f = &Harl::debug;
	levels[1].name = "info";
	levels[1].f = &Harl::info;
	levels[2].name = "warning";
	levels[2].f = &Harl::warning;
	levels[3].name = "error";
	levels[3].f = &Harl::error;
}

void Harl::debug(void)
{
	std::cout << "it's debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "it's info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "it's warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "it's error" << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (levels[i].name.compare(level) == 0)
			(this->*levels[i].f)();
	}
}
