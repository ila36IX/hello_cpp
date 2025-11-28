#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
      public:
        FragTrap(void);
        FragTrap(std::string);
        FragTrap &operator=(const FragTrap &);
        FragTrap(const FragTrap &);
        ~FragTrap();
        void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif
