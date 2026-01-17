#ifndef ICE_H
#define ICE_H
#include "AMateria.h"

class Ice : public AMateria
{
      public:
        Ice(void);
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        ~Ice();

        void use(ICharacter &target);
        AMateria *clone() const;
};

#endif
