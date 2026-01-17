#ifndef CURE_H
#define CURE_H

#include "AMateria.h"

class Cure: public AMateria
{
      public:
        Cure(void);
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        ~Cure();

        void use(ICharacter &target);
        AMateria *clone() const;
};

#endif
