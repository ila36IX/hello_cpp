#include "Harl.h"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

Harl::Harl(const Harl &other)
{
        (void)other;
}

Harl &Harl::operator=(const Harl &other)
{
        if (&other == this)
                return (*this);
        return (*this);
}

void Harl::debug(void)
{
        std::cout << "[DEBUG]\n";
	std::cout << "Abracadabra — just testing the spell.\n";
}

void Harl::info(void)
{
        std::cout << "[INFO]\n";
	std::cout << "The train to Hogwarts leaves at eleven.\n";
}

void Harl::warning(void)
{
        std::cout << "[WARNING]\n";
	std::cout <<"The Forbidden Forest is strictly off-limits.\n";
}

void Harl::error(void)
{
        std::cout << "[ERROR]\n";
	std::cout << "He-Who-Must-Not-Be-Named has returned.\n";
}

void Harl::complain(std::string level)
{
        void (Harl::*mem_func[4])() = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error,
        };
        std::string levels[4] = {
            "debug",
            "info",
            "warning",
            "error",
        };
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*mem_func[i])();
			// or (*this.*mem_func[i])();
			return ;
		}
	}
}
