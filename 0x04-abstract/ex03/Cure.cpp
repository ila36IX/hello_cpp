#include "Cure.h"
#include "AMateria.h"
#include "ICharacter.h"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure &other)
{
        *this = other;
}

Cure &Cure::operator=(const Cure &other)
{
        (void)other;
        return (*this);
}

Cure::~Cure()
{
}

void Cure::use(ICharacter &target)
{
        std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

AMateria *Cure::clone() const
{
        return new Cure();
}
