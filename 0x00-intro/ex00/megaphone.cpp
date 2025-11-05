#include <iostream>
#include <string>

std::string string_toupper(char *charptr)
{
	std::string s(charptr);

	for(size_t i = 0; i < s.size(); i++)
	{
		s[i] = std::toupper(s[i]);
	}
	return (s);
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < ac; i++)
			std::cout << string_toupper(av[i]);
		std::cout << "\n";
	}
	return (0);
}
