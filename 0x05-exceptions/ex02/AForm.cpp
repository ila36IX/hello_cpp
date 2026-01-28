#include "AForm.h"

const char *AForm::GradeTooHighException::what() const throw()
{
        return "Form require lower grade";
};

const char *AForm::GradeTooLowException::what() const throw()
{
        return "Form require higher grade";
};

const char *AForm::FormNotSigned::what() const throw()
{
        return "Executing a form needs a sign";
};

AForm::AForm(void) : m_name("Subject"), m_signed(false), m_sign(100), m_exec(50)
{
}

AForm::AForm(const std::string &name, int sign, int exec) : m_name(name), m_signed(false), m_sign(sign), m_exec(exec)
{
        check_grade(m_exec);
        check_grade(m_sign);
}

AForm::AForm(const AForm &o) : m_name(o.m_name), m_signed(o.m_signed), m_sign(o.m_sign), m_exec(o.m_exec)
{
}

AForm &AForm::operator=(const AForm &other)
{
        if (this != &other)
        {
                m_signed = other.m_signed;
        }
        return (*this);
}

AForm::~AForm()
{
}

void AForm::check_grade(int grade)
{
        if (grade < 1)
                throw GradeTooHighException();
        else if (grade > 150)
                throw GradeTooLowException();
}

int AForm::get_sign_grade() const
{
        return m_sign;
}

int AForm::get_exec_grade() const
{
        return m_exec;
}

const std::string &AForm::get_name() const
{
        return m_name;
}

bool AForm::is_signed() const
{
        return m_signed;
}

void AForm::be_signed(Bureaucrat &b)
{
        if (b.getGrade() > m_sign)
                throw GradeTooLowException();
        m_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
        if (!m_signed)
                throw FormNotSigned();
        if (executor.getGrade() > m_exec)
                throw GradeTooLowException();
        executeRun();
}

std::ostream &operator<<(std::ostream &os, AForm &f)
{
        // Report(exec:15,sign:50,Y)
        os << f.get_name() << "(sign:" << f.get_sign_grade() << ",exec:" << f.get_exec_grade() << ","
           << (f.is_signed() ? 'Y' : 'N') << ")";
        return os;
}
