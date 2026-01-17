#include "Ice.h"
#include "ICharacter.h"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice &other)
{
        *this = other;
}

Ice &Ice::operator=(const Ice &other)
{
        (void)other;
        return (*this);
}

AMateria *Ice::clone() const
{
        return new Ice();
}

Ice::~Ice()
{
}

void Ice::use(ICharacter &target)
{
        std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
