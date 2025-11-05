#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
        index  = 0;
        number = 0;
}

void PhoneBook::add_new_contact()
{
        Contact contact;

        contact.read_fields_stdin();
        contacts[index] = contact;
        index           = (index + 1) % 8;
        if (number < 8)
                number++;
}

void PhoneBook::preview()
{
        std::cout << "---------------------------------------------\n";
        std::cout << "|     index|first_name| last_name|  nickname|\n";
        std::cout << "---------------------------------------------\n";
        if (number == 0)
                std::cout << "|            Nothing to display             |\n";
        for (int i = 0; i < number; i++)
        {
                std::cout << "|" << std::setw(10) << i << "|";
                std::cout << std::setw(10) << contacts[i].preview_field("first_name") << '|';
                std::cout << std::setw(10) << contacts[i].preview_field("last_name") << '|';
                std::cout << std::setw(10) << contacts[i].preview_field("nickname") << '|';
                std::cout << "\n";
        }
        std::cout << "---------------------------------------------\n";
}

Contact PhoneBook::contact_at(int index_req)
{
        if (index_req < 0 || index_req >= number)
                throw std::out_of_range("No contact with requested index");
        return (contacts[index_req]);
}

int PhoneBook::contacts_nbr()
{
        return (number);
}
