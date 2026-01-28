#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"

class AForm
{
      private:
        const std::string m_name;
        bool m_signed;
        const int m_sign;
        const int m_exec;

        static void check_grade(int grade);

      public:
        AForm(void);
        AForm(const std::string &name, int sign, int exec);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();

        int get_sign_grade() const;
        int get_exec_grade() const;
        const std::string &get_name() const;
        bool is_signed() const;
        void be_signed(Bureaucrat &b);

        class GradeTooHighException : public std::exception
        {
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
                const char *what() const throw();
        };

        class FormNotSigned : public std::exception
        {
                const char *what() const throw();
        };

        void execute(Bureaucrat const &executor) const;
        virtual void executeRun() const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm &f);

#endif
