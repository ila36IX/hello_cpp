#include "Harl.h"

Harl::Harl()
{
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
        std::cout << "The Forbidden Forest is strictly off-limits.\n";
}

void Harl::error(void)
{
        std::cout << "[ERROR]\n";
        std::cout << "He-Who-Must-Not-Be-Named has returned.\n";
}

void Harl::complain(std::string level)
{
        int level_index       = -1;
        std::string levels[4] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR",
        };

        for (int i = 0; i < 4; i++)
        {
                if (levels[i] == level)
                        level_index = i;
        }
        switch (level_index)
        {
                case (0):
                        debug();
                case (1):
                        info();
                case (2):
                        warning();
                case (3):
                        error();
                        break;
                default:
                        std::cout << "[ Probably complaining about insignificant problems ]\n";
                        break;
        }
}
