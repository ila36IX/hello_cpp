#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include "AMateria.h"
#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
      private:
        AMateria *mem[4];

      public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        ~MateriaSource();

        void learnMateria(AMateria *);
        AMateria *createMateria(std::string const &type);
};

#endif
