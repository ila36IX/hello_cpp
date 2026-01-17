#include "Brain.h"
#include <iostream>

Brain::Brain(void)
{
        std::cout << "Brain: Defaul Constructor\n";
}

Brain::Brain(const Brain &other)
{
        std::cout << "Brain: Copy Constructor\n";
        *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
        std::cout << "Brain: Copy Assignment Constructor\n";
        if (this != &other)
        {
                for (int i = 0; i < 100; i++)
                {
                        ideas[i] = other.ideas[i];
                }
        }
        return (*this);
}

Brain::~Brain()
{
        std::cout << "Brain: Destructor\n";
}
