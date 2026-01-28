#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
      private:
        const std::string m_name;
        int m_grade;
        void check_grade() const;

      public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        const std::string &getName();
        int getGrade() const;
        void incr();
        void decr();
        void signForm(AForm &f);
        void executeForm(AForm const &form) const;

        class GradeTooHighException : public std::exception
        {
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &b);

#endif
