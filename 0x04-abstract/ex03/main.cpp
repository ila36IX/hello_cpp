#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "Ice.h"
#include "MateriaSource.h"

int main()
{
        AMateria *ice       = new Ice();
        AMateria *cure      = new Cure();
        IMateriaSource *src = new MateriaSource();
        ICharacter *c1      = new Character("tim");
        ICharacter *c2      = new Character("ben");

        src->learnMateria(ice);
        src->learnMateria(cure);

        c1->equip(src->createMateria("ice"));
        c1->equip(src->createMateria("cure"));

        c1->use(0, *c2);
        c1->use(1, *c2);

        AMateria *droped = static_cast<Character *>(c1)->get_slot_ptr(1);
        c1->unequip(1);
        delete droped;

        c1->use(1, *c2);

        delete src;
        delete c1;
        delete c2;

        return 0;
}
