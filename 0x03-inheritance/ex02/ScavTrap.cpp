#include "ScavTrap.h"

ScavTrap::ScavTrap(void)
{
        hit_points    = 100;
        energy_points = 50;
        attack_damage = 20;
        std::cout << "ScavTrap default constructed!\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
        hit_points    = 100;
        energy_points = 50;
        attack_damage = 20;
        std::cout << "ScavTrap " << this->name << " constructed!\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
        if (&rhs == this)
                return (*this);
        ClapTrap::operator=(rhs);
        return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
        std::cout << "ScavTrap Copy Constructor called\n";
}

void ScavTrap::attack(const std::string &target)
{
        if (this->hit_points <= 0)
        {
                std::cout << "ScavTrap " << this->name << " No hit points to attack!\n";
                return;
        }
        if (this->energy_points <= 0)
        {
                std::cout << "ScavTrap " << this->name << " No energy to attack!\n";
                return;
        }
        this->energy_points--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage
                  << " points of damage!\n";
}

ScavTrap::~ScavTrap()
{
        std::cout << "ScavTrap " << this->name << " destroyed!\n";
}

void ScavTrap::guardGate()
{
        std::cout << "ScavTrap " << this->name << " in Gate keeper mode!\n";
}
