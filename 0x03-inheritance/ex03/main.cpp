#include "DiamondTrap.h"

int main()
{
        {
                DiamondTrap dt("Jim");

                dt.attack("Kim");
                dt.beRepaired(12);
                dt.highFivesGuys();
                dt.guardGate();
                dt.whoAmI();
        }
        std::cout << "=========================\n\n";
        {
                DiamondTrap dt("Jim");

                dt.beRepaired(12);
                DiamondTrap dt2 = dt;
                dt2.highFivesGuys();
                dt2.guardGate();
                dt2.whoAmI();
        }
        std::cout << "=========================\n\n";
        {
                DiamondTrap dt("Jim");
                DiamondTrap dt2;
                dt2 = dt;

                dt2.attack("Kim");
                dt2.beRepaired(12);
                dt2.highFivesGuys();
                dt2.guardGate();
                dt2.whoAmI();
        }
        return 0;
}
