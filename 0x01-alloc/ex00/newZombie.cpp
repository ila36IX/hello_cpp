#include "Zombie.h"
/**
 * newZombie - Allocate new zombie
 *
 * @name: name of the new zombie
 *
 * Return: New allocated Zombie
 */
Zombie *newZombie(std::string name)
{
        return (new Zombie(name));
}
