#ifndef CHARACTER_H
#define CHARACTER_H

#include "AMateria.h"
#include "ICharacter.h"

class Character : public ICharacter
{
      private:
        std::string name;
        AMateria *slots[4];

      public:
        Character(void);
        Character(std::string name);
        Character(const Character &other);
        Character &operator=(const Character &other);
        ~Character();

        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
        AMateria *get_slot_ptr(int idx);
};

#endif
