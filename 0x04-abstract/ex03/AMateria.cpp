#include "AMateria.h"
#include "ICharacter.h"

AMateria::AMateria(void)
{
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(const AMateria &other)
{
        *this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
        (void)other;
        return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
        return type;
}

void AMateria::use(ICharacter &target)
{
        std::cout << "Undefined: * usege of Amateria " << target.getName() << " irrelevant *\n";

}
