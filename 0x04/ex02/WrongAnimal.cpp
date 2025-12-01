#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
        std::cout << "WrongAnimal: Default Constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
        *this = other;
        std::cout << "WrongAnimal: Copy Constructor\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
        if (this != &other)
                this->type = other.type;
        std::cout << "WrongAnimal: Assignment Operator\n";
        return *this;
}

WrongAnimal::~WrongAnimal()
{
        std::cout << "WrongAnimal: Destructor\n";
}

void WrongAnimal::makeSound() const
{
        std::cout << "WrongAnimal Sounds like WrongAnimal\n";
}

std::string WrongAnimal::getType() const
{
        return this->type;
}
