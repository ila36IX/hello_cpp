#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"

class Form
{
      private:
        const std::string m_name;
        bool m_signed;
        const int m_sign;
        const int m_exec;

        static void check_grade(int grade);

      public:
        Form(void);
        Form(const std::string &name, int sign, int exec);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

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
};

std::ostream &operator<<(std::ostream &os, Form &f);

#endif
