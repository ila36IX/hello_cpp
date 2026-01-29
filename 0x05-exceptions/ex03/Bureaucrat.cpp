#include "Bureaucrat.h"
#include "AForm.h"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
        return "Grade is too high";
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
        return "Grade is too low";
};

Bureaucrat::Bureaucrat(void) : m_name("Nobody"), m_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name), m_grade(grade)
{
        check_grade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : m_name(other.m_name), m_grade(other.m_grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
        if (this != &other)
        {
                m_grade = other.m_grade;
        }
        return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName()
{
        return m_name;
}

int Bureaucrat::getGrade() const
{
        return m_grade;
}

void Bureaucrat::check_grade() const
{
        if (m_grade < 1)
                throw GradeTooHighException();
        else if (m_grade > 150)
                throw GradeTooLowException();
}

void Bureaucrat::incr()
{
        m_grade--;
        check_grade();
}

void Bureaucrat::decr()
{
        m_grade++;
        check_grade();
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &b)
{
        std::cout << b.getName() << ", bureaucrat grade " << b.getGrade();
        return os;
}

void Bureaucrat::signForm(AForm &f)
{
        try
        {
                f.be_signed(*this);
                std::cout << m_name << " signed " << f.get_name() << "\n";
        }
        catch (std::exception &e)
        {
                std::cout << m_name << " couldn’t sign " << f.get_name() << " because " << e.what() << "\n";
        }
}

void Bureaucrat::executeForm(AForm const &form) const
{
        try
        {
                form.execute(*this);
                std::cout << m_name << " executed " << form.get_name() << "\n";
        }
        catch (std::exception &e)
        {
                std::cout << m_name << " cannot execute " << form.get_name() << " form because " << e.what() << "\n";
        }
}
