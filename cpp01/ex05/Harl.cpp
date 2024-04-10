#include "Harl.hpp"

Harl::Harl()
{
	levels["debug"] = &Harl::debug;
	levels["info"] = &Harl::info;
	levels["warning"] = &Harl::warning;
	levels["error"] = &Harl::error;
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
	if (levels.find(level) != levels.end())
		(this->*levels[level])();
}
