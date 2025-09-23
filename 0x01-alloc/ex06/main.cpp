#include "Harl.h"
#include <cstdlib>

int main(int ac, char **av)
{
        Harl harl;

        if (ac != 2)
        {
                std::cout <<"Usage: "<< av[0] << " <LEVEL>\n";
                exit(1);
        }
        harl.complain(av[1]);
}
