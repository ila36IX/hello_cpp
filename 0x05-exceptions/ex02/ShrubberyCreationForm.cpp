#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("yard")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
    AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
        if (this != &other)
        {
                AForm::operator=(other);
                target = other.target;
        }
        return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeRun() const
{
        std::string filename = target + "_shrubbery";
        std::ofstream file(filename.c_str());

        if (!file.is_open())
        {
                std::cout << "Error: Coudn't open " << filename << "\n";
                return;
        }
        file << "         v\n"
             << "        >X<\n"
             << "         A\n"
             << "        d$b\n"
             << "      .d\\g$$b.\n"
             << "    .d$i$$\\g$$b.\n"
             << "       d$$@b\n"
             << "      d\\g$$$ib\n"
             << "    .d$$$\\g$$$b\n"
             << "  .d$$@$$$$\\g$$ib.\n"
             << "      d$$i$$b\n"
             << "     d\\g$$$$@$b\n"
             << "  .d$@$$\\g$$$$$@b.\n"
             << ".d$$$$i$$$\\g$$$$$$b.\n"
             << "        ###\n"
             << "        ###\n"
             << "        ### mh\n";
}
