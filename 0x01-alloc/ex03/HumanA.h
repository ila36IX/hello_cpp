#ifndef HUMAN_A_H
#define HUMAN_A_H
#include "Weapon.h"
#include <iostream>

class HumanA
{
      private:
        Weapon *weapon;
        std::string name;

      public:
        HumanA(std::string name, Weapon &weapon);
        HumanA(const HumanA &);
        HumanA &operator=(const HumanA &);
        ~HumanA();
        void attack();
        void setWeapon(Weapon &);
};

#endif // !HUMAN_A_H
