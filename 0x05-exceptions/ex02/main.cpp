#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
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

void test_shrubbery_creation_form()
{
        // shrubbery requirements: sign:145,exec:137
        ShrubberyCreationForm form1("home1");
        ShrubberyCreationForm form2("home2");
        ShrubberyCreationForm form3("home3");

        Bureaucrat empl1("empl1", 150);
        Bureaucrat empl2("empl2", 145);
        Bureaucrat empl3("empl3", 137);

        std::cout << "\n\n--- Shrubbery Creation Form ---\n";

        bureau_sign(empl1, form1);
        bureau_exec(empl1, form1);

        bureau_sign(empl2, form2);
        bureau_exec(empl2, form2);

        bureau_sign(empl3, form3);
        bureau_exec(empl3, form3);

        bureau_sign(empl2, form1);
        bureau_exec(empl3, form1);
}

void test_robotomy_request_form()
{
        // robotomy requirements: sign:72,exec:45
        RobotomyRequestForm bipoler1("bipoler1");
        RobotomyRequestForm bipoler2("bipoler2");
        RobotomyRequestForm bipoler3("bipoler3");

        Bureaucrat empl1("empl1", 150);
        Bureaucrat empl2("empl2", 72);
        Bureaucrat empl3("empl3", 45);

        std::cout << "\n\n--- Robotomy Request Form ---\n";

        bureau_sign(empl1, bipoler1);
        bureau_exec(empl1, bipoler1);

        bureau_sign(empl2, bipoler2);
        bureau_exec(empl2, bipoler2);

        bureau_sign(empl3, bipoler3);
        bureau_exec(empl3, bipoler3);

        bureau_sign(empl2, bipoler1);
        bureau_exec(empl3, bipoler3);
}

void test_presidential_pardon_form()
{
        // robotomy requirements: sign:25,exec:5
        PresidentialPardonForm arther1("arther1");
        PresidentialPardonForm arther2("arther2");
        PresidentialPardonForm arther3("arther3");

        Bureaucrat empl1("empl1", 150);
        Bureaucrat empl2("empl2", 25);
        Bureaucrat king("King", 1);

        std::cout << "\n\n--- Presidential Pardon Form ---\n";

        bureau_sign(empl1, arther1);
        bureau_exec(empl1, arther1);

        bureau_sign(empl2, arther2);
        bureau_exec(empl2, arther2);

        bureau_sign(king, arther3);
        bureau_exec(king, arther3);

        bureau_sign(empl2, arther1);
        bureau_exec(king, arther3);
}

int main()
{
        test_shrubbery_creation_form();
        test_robotomy_request_form();
        test_presidential_pardon_form();
}
