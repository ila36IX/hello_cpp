#include "PhoneBook.h"

void get_index_display_contact(PhoneBook &ph)
{
        int index;
        std::string nbr;

        if (ph.contacts_nbr() == 0)
                return;
        while (1)
        {
                if (std::cin.eof())
                        break;
                std::cout << "Index (-1 to cancel): ";
                getline(std::cin, nbr);
                if (!std::cin.good())
                        break;
                try
                {
                        index = str_to_int(nbr);
                        if (index == -1)
                                break;
                        ph.contact_at(index).full_display_all();
                        break;
                }
                catch (std::exception &e)
                {
                        std::cout << RED_BOLD << e.what() << "\n" << TEXT_RESET;
                }
        }
}

int main()
{
        PhoneBook pb;
        std::string action;

        while (std::cin.good())
        {
                std::cout << "(ADD, SEARCH, EXIT)$ ";
                std::getline(std::cin, action);
                if (!std::cin.good())
                        return 1;
                if (action == "ADD")
                        pb.add_new_contact();
                else if (action == "SEARCH")
                {
                        pb.preview();
                        get_index_display_contact(pb);
                }
                else if (action == "EXIT")
                        break;
                else
                        std::cout << RED_BOLD << "Unknown command `" << action << "`\n" TEXT_RESET;
        }
        return (0);
}
