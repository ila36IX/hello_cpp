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
        /**
         * Defines a type of a harl member class.
         * Note: member functions are not like the ordinary, thats why this syntax is required
         *
         * Check: https://isocpp.org/wiki/faq/pointers-to-members
         */
        typedef void (Harl::*HarlMemFn)();

        // Or: void (Harl::*mem_func[4])();
        HarlMemFn mem_func[4] = {
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
                        // Best: std::invoke(mem_func[i], this);
                        // Or  : (*this.*mem_func[i])();
                        // Or  : (this->*mem_func[i])();
                        CALL_MEMBER_FN(*this, mem_func[i])();
                        return;
                }
        }
}
