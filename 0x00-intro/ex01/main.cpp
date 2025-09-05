#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

#define WHITE_BOLD "\e[1;37m"
#define RED_BOLD "\e[1;31m"
#define TEXT_RESET "\e[0m"

inline void string_trim(std::string &str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact(void) {};

	Contact(std::string _first_name, std::string _last_name, std::string _nickname, std::string _phone_number,
			std::string _darkest_secret) :
		first_name(first_name),
		last_name(last_name),
		nickname(nickname),
		phone_number(phone_number),
		darkest_secret(darkest_secret),
	{
		first_name = _first_name;
		last_name = _last_name;
		nickname = _nickname;
		phone_number = _phone_number;
		darkest_secret = _darkest_secret;
	}

	void read_fields_stdin()
	{
		Contact::read_field("First name", first_name);
		Contact::read_field("Last name", last_name);
		Contact::read_field("Nickname", nickname);
		Contact::read_field("Phone Number", phone_number);
		Contact::read_field("Darkest secret", darkest_secret);
	}

	std::string get_field(const std::string &field_name)
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

	std::string preview_field(const std::string &field_name)
	{
		std::string field(Contact::get_field(field_name));

		if (field.size() < 10)
			return (field);
		else
			return (field.substr(0, 9) + ".");
		return (field);
	}

	void read_field(const std::string &prefix, std::string &field)
	{
		while (1)
		{
			if (!std::cin.good())
				return;
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

	void full_display_all(void)
	{
		std::cout << WHITE_BOLD << "First name: " << TEXT_RESET << first_name << "\n";
		std::cout << WHITE_BOLD << "Last name: " << TEXT_RESET << last_name << "\n";
		std::cout << WHITE_BOLD << "Nickname: " << TEXT_RESET << nickname << "\n";
		std::cout << WHITE_BOLD << "Phone Number: " << TEXT_RESET << phone_number << "\n";
		std::cout << WHITE_BOLD << "Darkest secret: " << TEXT_RESET << darkest_secret << "\n";
	}
};

class PhoneBook
{
  private:
	Contact contacts[8];
	int index;
	int number;

  public:
	PhoneBook()
	{
		index = 0;
		number = 0;
	}

	void add_new_contact(void)
	{
		Contact contact;

		contact.read_fields_stdin();
		contacts[index] = contact;
		index = (index + 1) % 8;
		if (number < 8)
			number++;
	}

	void preview()
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

	Contact contact_at(int index_req)
	{
		if (index_req < 0 || index_req >= number)
			throw std::out_of_range("No contact with requested index");
		return (contacts[index_req]);
	}

	/**
	 * contacts_nbr - gives number of contacts in db
	 */
	int contacts_nbr()
	{
		return (number);
	}
};

inline void delete_leftovers_cin()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

int str_to_int(std::string nbr)
{
	long int result = 0;
	int negative = 1;
	int i = 0;

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
