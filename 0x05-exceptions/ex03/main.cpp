#include "AForm.h"
#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <cstring>
#include <fstream>

void bureau_work(AForm &form)
{
        Bureaucrat king("King", 1);

        std::cout << "\n";
        std::cout << form << "\n";
        king.signForm(form);
        std::cout << form << "\n";
        king.executeForm(form);
        std::cout << "\n";
}

int main()
{
        Intern someRandomIntern;
        AForm *rob;
        AForm *pres;
        AForm *tree;
        AForm *none = 0;

        rob  = someRandomIntern.makeForm("robotomy request", "Bender");
        pres = someRandomIntern.makeForm("presidential pardon", "Hannibal");
        tree = someRandomIntern.makeForm("shrubbery creation", "yard");
        none = someRandomIntern.makeForm("Unkown form", "yard");

        bureau_work(*rob);
        bureau_work(*pres);
        bureau_work(*tree);
        // bureau_work(*none);

        delete rob;
        delete pres;
        delete tree;
        delete none;
}
