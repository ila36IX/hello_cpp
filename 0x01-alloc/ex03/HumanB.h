#ifndef HUMAN_B_H
#define HUMAN_B_H
#include <string>
#include "Weapon.h"
#include <iostream>
#include <cstddef>

class HumanB
{
      private:
        Weapon *weapon;
        std::string name;

      public:
        HumanB(std::string name);
        HumanB(const HumanB &);
        HumanB &operator=(const HumanB &);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &);
};
#endif // !HUMAN_B_H
