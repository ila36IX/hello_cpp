#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal()
{
        this->type = "WrongCat";
        std::cout << "WrongCat: Default Constructor\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
        *this = other;
        std::cout << "WrongCat: Copy Constructor\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
        if (this != &other)
                this->type = other.type;
        std::cout << "WrongCat: Assignment Operator\n";
        return *this;
}

WrongCat::~WrongCat()
{
        std::cout << "WrongCat: Destructor\n";
}

void WrongCat::makeSound() const
{
        std::cout << "WrongCat Sounds like WrongCat\n";
}
