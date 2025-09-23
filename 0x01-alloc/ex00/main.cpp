#include "Zombie.h"

int main(void)
{
        Zombie *zz = newZombie("kim");

        zz->announce();
        delete zz;
        randomChump("Ben");
        return (0);
}
