#include "Character.h"

Character::Character(void)
{
        for (int i = 0; i < 4; i++)
                slots[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
        for (int i = 0; i < 4; i++)
                slots[i] = NULL;
}

Character::Character(const Character &other)
{
        *this = other;
}

Character &Character::operator=(const Character &other)
{
        if (this == &other)
                return (*this);
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
                delete slots[i];
                if (other.slots[i])
                        slots[i] = other.slots[i]->clone();
        }
        return (*this);
}

Character::~Character()
{
        for (int i = 0; i < 4; i++)
                delete slots[i];
}

std::string const &Character::getName() const
{
        return name;
}

void Character::equip(AMateria *m)
{
        for (int i = 0; i < 4; i++)
        {
                if (!slots[i])
                {
                        slots[i] = m;
                        return;
                }
        }
}

void Character::unequip(int idx)
{
        slots[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
        if (idx >= 0 && idx < 4 && slots[idx])
        {
                std::cout << name << ": ";
                slots[idx]->use(target);
        }
}

AMateria *Character::get_slot_ptr(int idx)
{
        if (idx >= 0 && idx < 4 && slots[idx])
                return slots[idx];
        return NULL;
}
