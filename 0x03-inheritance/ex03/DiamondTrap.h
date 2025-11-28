#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap
{
      private:
        std::string name;

      public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();
        void whoAmI();
        using ScavTrap::attack;
};

#endif
