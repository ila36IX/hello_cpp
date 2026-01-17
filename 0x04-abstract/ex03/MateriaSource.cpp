#include "MateriaSource.h"
#include "AMateria.h"

MateriaSource::MateriaSource(void)
{
        for (int i = 0; i < 4; i++)
                mem[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
        *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
        if (this != &other)
        {
                for (int i = 0; i < 4; i++)
                {
                        delete mem[i];
                        mem[i] = NULL;
                        if (other.mem[i])
                                mem[i] = other.mem[i]->clone();
                }
        }
        return (*this);
}

MateriaSource::~MateriaSource()
{
        for (int i = 0; i < 4; i++)
                delete mem[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
        for (int i = 0; i < 4 && m; i++)
        {
                if (!mem[i])
                {
                        mem[i] = m->clone();
                        delete m;
                        return;
                }
        }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
        for (int i = 0; i < 4; i++)
        {
                if (mem[i] && mem[i]->getType() == type)
                        return mem[i]->clone();
        }
        return 0;
}
