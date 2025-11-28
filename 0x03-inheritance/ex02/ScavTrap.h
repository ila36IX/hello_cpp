#ifndef SCAV_TRAP
#define SCAV_TRAP

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
      public:
        ScavTrap(void);
        ScavTrap(std::string);
        ScavTrap &operator=(const ScavTrap &);
        ScavTrap(const ScavTrap &);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string &target);
};

#endif
