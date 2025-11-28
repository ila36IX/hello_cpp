#include "ClapTrap.h"

ClapTrap::ClapTrap(void) : hit_points(10), energy_points(10), attack_damage(0)
{
        std::cout << "ClapTrap " << this->name << " default constructed!" << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) :
    name(other.name),
    hit_points(other.hit_points),
    energy_points(other.energy_points),
    attack_damage(other.attack_damage)
{
        std::cout << "ClapTrap " << this->name << " copy constructed!" << "\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
        if (&other == this)
                return (*this);
        this->name          = other.name;
        this->hit_points    = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
        return (*this);
}

ClapTrap::ClapTrap(std::string _name) : name(_name), hit_points(10), energy_points(10), attack_damage(0)
{
        std::cout << "ClapTrap " << this->name << " constructed!" << "\n";
}

ClapTrap::~ClapTrap()
{
        std::cout << "ClapTrap " << this->name << " destroyed!\n";
}

void ClapTrap::attack(const std::string &target)
{
        if (this->hit_points <= 0)
        {
                std::cout << "ClapTrap " << this->name << " No hit points to attack!\n";
                return;
        }
        if (this->energy_points <= 0)
        {
                std::cout << "ClapTrap " << this->name << " No energy to attack!";
                return;
        }
        this->energy_points--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage
                  << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
        if (this->hit_points <= 0)
        {
                std::cout << "ClapTrap " << this->name << " No hit points to repair!\n";
                return;
        }
        if (this->energy_points <= 0)
        {
                std::cout << "ClapTrap " << this->name << " No energy to repair!\n";
                return;
        }
        this->energy_points--;
        this->hit_points += amount;
        std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << "\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
        this->hit_points -= amount;
        if (this->hit_points < 0)
                this->hit_points = 0;
        std::cout << "ClapTrap " << this->name << " took " << amount << " damage!\n";
}
