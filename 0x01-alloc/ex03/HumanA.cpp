#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon)
{
        this->weapon = &weapon;
        this->name   = name;
}

HumanA::HumanA(const HumanA &other) : weapon(other.weapon), name(other.name)
{
}

HumanA &HumanA::operator=(const HumanA &other)
{
        if (this == &other)
        {
                return (*this);
        }
        this->name   = other.name;
        this->weapon = other.weapon;
        return (*this);
}

HumanA::~HumanA(void)
{
}

void HumanA::setWeapon(Weapon &weapon)
{
        this->weapon = &weapon;
}

void HumanA::attack(void)
{
        std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
}
