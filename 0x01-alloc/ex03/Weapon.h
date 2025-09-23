#include <string>
#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
      private:
        std::string type;

      public:
        Weapon(std::string type);
        Weapon(const Weapon &other);
        Weapon &operator=(const Weapon &);
        ~Weapon();
        std::string getType();
        void setType(std::string type);
};

#endif
