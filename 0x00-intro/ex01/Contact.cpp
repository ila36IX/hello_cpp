#include "Contact.h"

Contact::Contact() {};

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number,
                 std::string darkest_secret) :
    first_name(first_name),
    last_name(last_name),
    nickname(nickname),
    phone_number(phone_number),
    darkest_secret(darkest_secret)
{
}

void Contact::read_fields_stdin()
{
        Contact::read_field("First name", first_name);
        Contact::read_field("Last name", last_name);
        Contact::read_field("Nickname", nickname);
        Contact::read_field("Phone Number", phone_number);
        Contact::read_field("Darkest secret", darkest_secret);
}

std::string Contact::get_field(const std::string &field_name)
{
        if ("first_name" == field_name)
                return (first_name);
        if ("last_name" == field_name)
                return (last_name);
        if ("nickname" == field_name)
                return (nickname);
        if ("phone_number" == field_name)
                return (phone_number);
        if ("darkest_secret" == field_name)
                return (darkest_secret);
        throw std::runtime_error("Unknown field: " + field_name);
}

std::string Contact::preview_field(const std::string &field_name)
{
        std::string field(Contact::get_field(field_name));

        if (field.size() < 10)
                return (field);
        else
                return (field.substr(0, 9) + ".");
        return (field);
}

void Contact::read_field(const std::string &prefix, std::string &field)
{
        while (true)
        {
                if (!std::cin.good())
                {
                        return;
                }
                std::cout << prefix << " > ";
                std::getline(std::cin, field);
                if (!std::cin.good())
                        return;
                string_trim(field);
                if (field.empty())
                {
                        std::cout << RED_BOLD << "The " + prefix + " is empty\n" << TEXT_RESET;
                        continue;
                }
                return;
        }
}

void Contact::full_display_all(void)
{
        std::cout << WHITE_BOLD << "First name: " << TEXT_RESET << first_name << "\n";
        std::cout << WHITE_BOLD << "Last name: " << TEXT_RESET << last_name << "\n";
        std::cout << WHITE_BOLD << "Nickname: " << TEXT_RESET << nickname << "\n";
        std::cout << WHITE_BOLD << "Phone Number: " << TEXT_RESET << phone_number << "\n";
        std::cout << WHITE_BOLD << "Darkest secret: " << TEXT_RESET << darkest_secret << "\n";
}
