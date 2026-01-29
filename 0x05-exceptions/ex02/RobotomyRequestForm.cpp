#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("bipolar")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
    AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
        if (this != &other)
        {
                AForm::operator=(other);
                target = other.target;
        }
        return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeRun() const
{
        std::cout << "* drilling noises *\n";
        if (std::rand() % 2)
                std::cout << target << " robotomized successfully\n";
        else
                std::cout << target << " robotomy failed\n";
}
