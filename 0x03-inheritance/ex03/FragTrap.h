#ifndef FRAG_TRAP_h
#define FRAG_TRAP_h

#include "ClapTrap.h"

class FragTrap : virtual public ClapTrap
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
