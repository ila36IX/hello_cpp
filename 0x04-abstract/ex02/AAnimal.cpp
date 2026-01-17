#include "AAnimal.h"

AAnimal::AAnimal() : type("AAnimal")
{
        std::cout << "AAnimal: Default Constructor called\n";
}

AAnimal::AAnimal(const AAnimal &other)
{
        std::cout << "AAnimal: Copy Constructor called\n";
        *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
        std::cout << "AAnimal: Assignment Operator called\n";
        if (this != &other)
        {
                this->type = other.type;
        }
        return *this;
}

AAnimal::~AAnimal()
{
        std::cout << "AAnimal: Destructor called\n";
}

std::string AAnimal::getType() const
{
        return this->type;
}
