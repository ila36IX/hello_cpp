#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H
#include "AForm.h"

class PresidentialPardonForm : public AForm
{
      private:
        std::string target;

      public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        void executeRun() const;
};

#endif
