#include "Dog.h"

Dog::Dog() : Animal()
{
        this->type = "Dog";
        std::cout << "Dog: Default Constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
        std::cout << "Dog: Copy Constructor callea\n";
        *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
        std::cout << "Dog: Assignment Operator called\n";
        if (this != &other)
        {
                this->type = other.type;
        }
        return *this;
}

Dog::~Dog()
{
        std::cout << "Dog: Destructor called\n";
}

void Dog::makeSound() const
{
        std::cout << "Dog Sounds Like Dog...\n";
}
