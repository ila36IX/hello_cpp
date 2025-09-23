#include "Weapon.h"

Weapon::Weapon(std::string type)
{
        this->type = type;
}

Weapon::Weapon(const Weapon &other) : type(other.type)
{
}

Weapon &Weapon::operator=(const Weapon &other)
{
        if (this == &other)
        {
                return (*this);
        }
        this->type = other.type;
        return (*this);
}

std::string Weapon::getType()
{
        return (this->type);
}

void Weapon::setType(std::string type)
{
        this->type = type;
}

Weapon::~Weapon()
{
}
