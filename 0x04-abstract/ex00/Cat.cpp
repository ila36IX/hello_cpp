#include "Cat.h"

Cat::Cat() : Animal()
{
        this->type = "Cat";
        std::cout << "Cat: Default Constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
        std::cout << "Cat: Copy Constructor called\n";
        *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
        std::cout << "Cat: Assignment Operator called\n";
        if (this != &other)
                this->type = other.type;
        return *this;
}

Cat::~Cat()
{
        std::cout << "Cat: Destructor called\n";
}

void Cat::makeSound() const
{
        std::cout << "Cat Sounds Like Cat\n";
}
