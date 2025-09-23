#include "HumanB.h"

HumanB::HumanB(std::string name)
{
        this->weapon = NULL;
        this->name   = name;
}

HumanB::HumanB(const HumanB &other) : weapon(other.weapon), name(other.name)
{
}

HumanB &HumanB::operator=(const HumanB &other)
{
        if (this == &other)
        {
                return (*this);
        }
        this->name   = other.name;
        this->weapon = other.weapon;
        return (*this);
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon &weapon)
{
        this->weapon = &weapon;
}

void HumanB::attack(void)
{
        if (this->weapon)
                std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
        else
                std::cout << this->name << " don't have weapon\n";
}
