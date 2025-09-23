#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
      private:
        std::string name;

      public:
        Zombie(void);
        Zombie(std::string name);
        Zombie(Zombie const &other);
        Zombie &operator=(const Zombie &other);
        ~Zombie();
        void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif /* ZOMBIE_H */
