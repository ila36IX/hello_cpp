#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

void with_virtual(const Animal *animal)
{
        std::cout << "Type: " << animal->getType() << "\n";
        animal->makeSound();
}

void without_virtual(const WrongAnimal *r_animal)
{
        std::cout << "Type: " << r_animal->getType() << "\n";
        r_animal->makeSound();
}

int main()
{

        {
                const Animal *meta = new Animal();
                const Animal *j    = new Dog();
                const Animal *i    = new Cat();

                with_virtual(meta);
                with_virtual(j);
                with_virtual(i);
                delete meta;
                delete j;
                delete i;
        }
        std::cout << "\n---------------------\n\n";
        {
                const WrongAnimal *meta = new WrongAnimal();
                const WrongAnimal *i    = new WrongCat();

                without_virtual(meta);
                without_virtual(i);
                delete meta;
                delete i;
        }
}
