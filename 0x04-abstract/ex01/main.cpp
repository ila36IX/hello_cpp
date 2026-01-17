#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main()
{
        Animal *animals[10];
        int nbr = 10;

        for (int i = 0; i < nbr; i++)
        {
                if (i >= nbr / 2)
                {
                        animals[i] = new Dog;
                }
                else
                {
                        animals[i] = new Cat;
                }
        }
        for (int i = 0; i < nbr; i++)
        {
                animals[i]->makeSound();
        }
        for (int i = 0; i < nbr; i++)
        {
                delete animals[i];
        }

        std::cout << "\n------- No shallow copy -------\n\n";
        Cat cat1;
        Cat cat2(cat1);
        Dog *dog1 = new Dog;
        Dog *dog2 = new Dog(*dog1);
        delete dog1;
        delete dog2;
        return (0);
}
