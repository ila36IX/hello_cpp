#include "Cat.h"
#include "Brain.h"

Cat::Cat() : AAnimal()
{
        this->type = "Cat";
        brain      = new Brain;
        std::cout << "Cat: Default Constructor called\n";
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
        std::cout << "Cat: Copy Constructor called\n";
        *this = other;
        brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
        std::cout << "Cat: Assignment Operator called\n";
        if (this != &other)
        {
                this->type = other.type;
        }
        return *this;
}

Cat::~Cat()
{
        delete brain;
        std::cout << "Cat: Destructor called\n";
}

void Cat::makeSound() const
{
        std::cout << "Cat Sounds Like Cat\n";
}
