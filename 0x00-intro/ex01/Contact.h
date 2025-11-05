#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <stdexcept>
#include <iostream>
#include "utils.h"

#define WHITE_BOLD "\e[1;37m"
#define RED_BOLD "\e[1;31m"
#define TEXT_RESET "\e[0m"

class Contact
{
      private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

      public:
        Contact();
        Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number,
                std::string darkest_secret);
        void read_fields_stdin();
        std::string get_field(const std::string &field_name);
        std::string preview_field(const std::string &field_name);
        static void read_field(const std::string &prefix, std::string &field);
        void full_display_all(void);
};

#endif // !CONTACT_H
