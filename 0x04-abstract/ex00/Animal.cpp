#include "Animal.h"

Animal::Animal() : type("Animal")
{
        std::cout << "Animal: Default Constructor called\n";
}

Animal::Animal(const Animal &other)
{
        std::cout << "Animal: Copy Constructor called\n";
        *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
        std::cout << "Animal: Assignment Operator called\n";
        if (this != &other)
                this->type = other.type;
        return *this;
}

Animal::~Animal()
{
        std::cout << "Animal: Destructor called\n";
}

void Animal::makeSound() const
{
        std::cout << "Animal: Noises...\n";
}

std::string Animal::getType() const
{
        return this->type;
}
