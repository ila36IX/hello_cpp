#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "AForm.h"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
      private:
        std::string target;

      public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        void executeRun() const;
};

#endif
