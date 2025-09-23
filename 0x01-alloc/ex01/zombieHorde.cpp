#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name)
{
        Zombie *zombies = new Zombie[N];
        Zombie tmp      = name;

        for (int i = 0; i < N; i++)
                zombies[i] = tmp;
        return (zombies);
}
