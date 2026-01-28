#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include <cstring>
#include <fstream>

void bureau_sign(Bureaucrat &b, AForm &f)
{
        try
        {
                b.signForm(f);
        }
        catch (std::exception &e)
        {
                std::cout << e.what() << "\n";
        }
}

void bureau_exec(Bureaucrat &b, AForm &f)
{
        try
        {
                b.executeForm(f);
        }
        catch (std::exception &e)
        {
                std::cout << e.what() << "\n";
        }
}

int main()
{
        // shrubbery requirements: sign:145,exec:137
        ShrubberyCreationForm form1("home1");
        ShrubberyCreationForm form2("home2");
        ShrubberyCreationForm form3("home3");

        Bureaucrat empl1("empl1", 150);
        Bureaucrat empl2("empl2", 145);
        Bureaucrat empl3("empl3", 137);

        bureau_sign(empl1, form1);
        bureau_exec(empl1, form1);

        bureau_sign(empl2, form2);
        bureau_exec(empl2, form2);

        bureau_sign(empl3, form3);
        bureau_exec(empl3, form3);

        bureau_sign(empl3, form1);
        bureau_exec(empl2, form1);
}
