#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include "AForm.h"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
      private:
        std::string target;

      public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        void executeRun() const;
};

#endif
