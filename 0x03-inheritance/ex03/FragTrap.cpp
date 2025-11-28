#include "FragTrap.h"

FragTrap::FragTrap(void)
{
        hit_points    = 100;
        energy_points = 100;
        attack_damage = 30;
        std::cout << "FragTrap default constructed!\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
        hit_points    = 100;
        energy_points = 100;
        attack_damage = 30;
        std::cout << "FragTrap " << this->name << " constructed!\n";
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
        if (&rhs == this)
                return (*this);
        ClapTrap::operator=(rhs);
        return (*this);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
        std::cout << "FragTrap Copy Constructor called\n";
}

void FragTrap::attack(const std::string &target)
{
        if (this->hit_points <= 0)
        {
                std::cout << "FragTrap " << this->name << " No hit points to attack!\n";
                return;
        }
        if (this->energy_points <= 0)
        {
                std::cout << "FragTrap " << this->name << " No energy to attack!\n";
                return;
        }
        this->energy_points--;
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage
                  << " points of damage!\n";
}

FragTrap::~FragTrap()
{
        std::cout << "FragTrap " << this->name << " destroyed!\n";
}

void FragTrap::highFivesGuys(void)
{
        std::cout << "FragTrap " << this->name << " wants to high-fives\n";
}
