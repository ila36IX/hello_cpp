#include "Form.h"

void init_from(const char *name, int sign, int exec)
{
        try
        {
                Form form(name, sign, exec);
                std::cout << form << "\n";
        }
        catch (std::exception &e)
        {
                std::cout << e.what() << "\n";
        }
}

int main()
{
        std::cout << "----- Just good -----\n";
        init_from("FORM.1", 150, 149);
        init_from("FORM.2", 1, 2);
        init_from("FORM.3", 2, 2);

        std::cout << "\n----- To high -----\n";
        init_from("FORM.4", 98, 0);
        init_from("FORM.5", 0, 98);

        std::cout << "\n----- To low -----\n";
        init_from("FORM.4", 1337, 15);
        init_from("FORM.5", 15, 1337);

        Form sensitive("sensitive", 1, 5);
        Form regular("regular", 98, 5);

        Bureaucrat director("Director", 1);
        Bureaucrat noob("noob", 90);

        std::cout << "\n----- Director Can sign everything -----\n";
        director.signForm(sensitive);
        director.signForm(regular);

        std::cout << "\n----- Noob Cannot sign everything -----\n";
        noob.signForm(sensitive);
        noob.signForm(regular);
}
