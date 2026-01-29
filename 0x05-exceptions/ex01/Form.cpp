#include "Form.h"

Form::Form(void) : m_name("Subject"), m_signed(false), m_sign(100), m_exec(50)
{
}

Form::Form(const std::string &name, int sign, int exec) : m_name(name), m_signed(false), m_sign(sign), m_exec(exec)
{
        check_grade(m_exec);
        check_grade(m_sign);
}

Form::Form(const Form &o) : m_name(o.m_name), m_signed(o.m_signed), m_sign(o.m_sign), m_exec(o.m_exec)
{
}

Form &Form::operator=(const Form &other)
{
        if (this != &other)
        {
                m_signed = other.m_signed;
        }
        return (*this);
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
        return "Form require lower grade";
};

const char *Form::GradeTooLowException::what() const throw()
{
        return "Form require higher grade";
};

void Form::check_grade(int grade)
{
        if (grade < 1)
                throw GradeTooHighException();
        else if (grade > 150)
                throw GradeTooLowException();
}

int Form::get_sign_grade() const
{
        return m_sign;
}

int Form::get_exec_grade() const
{
        return m_exec;
}

const std::string &Form::get_name() const
{
        return m_name;
}

bool Form::is_signed() const
{
        return m_signed;
}

void Form::be_signed(Bureaucrat &b)
{
        if (b.getGrade() > m_sign)
                throw GradeTooLowException();
        m_signed = true;
}

std::ostream &operator<<(std::ostream &os, Form &f)
{
        // Report(exec:15,sign:50,Y)
        os << f.get_name() << "(sign:" << f.get_sign_grade() << ",exec:" << f.get_exec_grade() << ","
           << (f.is_signed() ? 'Y' : 'N') << ")";
        return os;
}
