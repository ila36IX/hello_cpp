#include "Zombie.h"

Zombie::Zombie(void) {};

Zombie::Zombie(std::string name) : name(name) {};

Zombie::Zombie(const Zombie &other) : name(other.name)
{
}

Zombie &Zombie::operator=(const Zombie &other)
{
        if (this == &other)
        {
                return (*this);
        }
        this->name = other.name;
        return (*this);
}

Zombie::~Zombie() {
        std::cout << this->name << ": Goodbye\n";
};

void Zombie::announce()
{
        std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
