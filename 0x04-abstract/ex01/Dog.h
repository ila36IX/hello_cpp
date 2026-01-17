#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
      private:
        Brain *brain;

      public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();
        void makeSound() const;
};

#endif
