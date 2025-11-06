#include "Zombie.h"

int main()
{
        int nbr         = 10;
        Zombie *zombies = zombieHorde(nbr, "Hulk");

        for (int i = 0; i < nbr; i++)
        {
                zombies[i].announce();
        }

        delete[] zombies;
        return 0;
}
