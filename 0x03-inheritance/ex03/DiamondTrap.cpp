#include "DiamondTrap.h"

DiamondTrap::DiamondTrap(void)
{
        hit_points    = 100;
        energy_points = 50;
        attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
        hit_points    = 100;
        energy_points = 50;
        attack_damage = 30;
        std::cout << "DiamondTrap " << name << " Constructed\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
        name           = other.name;
        hit_points     = other.hit_points;
        energy_points  = other.energy_points;
        attack_damage  = other.attack_damage;
        ClapTrap::name = other.ClapTrap::name;
        std::cout << "DiamondTrap " << name << " copy Constructor\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
        if (this != &rhs)
        {
                hit_points     = rhs.hit_points;
                energy_points  = rhs.energy_points;
                attack_damage  = rhs.attack_damage;
                ClapTrap::name = rhs.ClapTrap::name;
                name           = rhs.name;
                std::cout << "DiamondTrap " << name << " assign operator\n";
        }
        return (*this);
}

DiamondTrap::~DiamondTrap()
{
        std::cout << "DiamondTrap " << this->name << " destroyed!\n";
}

void DiamondTrap::whoAmI()
{
        std::cout << "DiamondTrap " << name << ", ClapTrap " << ClapTrap::name << "\n";
}
