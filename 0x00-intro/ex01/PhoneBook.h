#include "Contact.h"
#include <iomanip>

class PhoneBook
{
      private:
        Contact contacts[8];
        int index;
        int number;

      public:
        PhoneBook();
        void add_new_contact();
        void preview();
        Contact contact_at(int index_req);
        int contacts_nbr();
};
