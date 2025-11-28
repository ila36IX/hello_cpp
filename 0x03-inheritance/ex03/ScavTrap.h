#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap
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

#endif /* SCAV_TRAP_H */
