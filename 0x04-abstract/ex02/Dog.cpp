#include "Dog.h"

Dog::Dog() : AAnimal()
{
        this->type = "Dog";
        brain      = new Brain;
        std::cout << "Dog: Default Constructor called\n";
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
        std::cout << "Dog: Copy Constructor callea\n";
        *this = other;
        brain = new Brain(*other.brain);
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
        delete brain;
        std::cout << "Dog: Destructor called\n";
}

void Dog::makeSound() const
{
        std::cout << "Dog Sounds Like Dog...\n";
}
