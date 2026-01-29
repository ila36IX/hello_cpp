#ifndef INTERN_H
#define INTERN_H
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

typedef struct s_record
{
        AForm *prototype;
        std::string name;
} Record;

class Intern
{
      private:
        Record m_records[3];
        int m_size;

      public:
        Intern(void);
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
        AForm *makeForm(const std::string &type, const std::string &target) const;
};

#endif
