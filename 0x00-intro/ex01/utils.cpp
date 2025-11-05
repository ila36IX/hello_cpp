#include "utils.h"

inline void string_trim(std::string &str)
{
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
}

inline void delete_leftovers_cin()
{
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
}

int str_to_int(std::string nbr)
{
        long int result = 0;
        int negative    = 1;
        size_t i        = 0;

        string_trim(nbr);
        if (nbr[i] == '-')
                negative = -1;
        if (nbr[i] == '-' || nbr[i] == '+')
                i++;
        if (i == nbr.size())
                throw std::invalid_argument("Invalid number");
        for (; i < nbr.size() && std::isdigit(nbr[i]); ++i)
        {
                result = result * 10 + nbr[i] - '0';
                if (result > INT_MAX && negative == 1)
                        throw std::out_of_range("Number is out of range");
        }
        if (i != nbr.size())
                throw std::invalid_argument("Invalid number");
        return (result * negative);
}
