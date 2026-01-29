#include "Intern.h"

static Record init_record(const std::string &name, AForm *form)
{
        Record record;
        record.name      = name;
        record.prototype = form;
        return record;
}

Intern::Intern(void)
{
        m_size              = 0;
        m_records[m_size++] = init_record("presidential pardon", new PresidentialPardonForm);
        m_records[m_size++] = init_record("robotomy request", new RobotomyRequestForm);
        m_records[m_size++] = init_record("shrubbery creation", new ShrubberyCreationForm);
}

Intern::Intern(const Intern &other)
{
        m_size              = 0;
        m_records[m_size++] = init_record("presidential pardon", new PresidentialPardonForm);
        m_records[m_size++] = init_record("robotomy request", new RobotomyRequestForm);
        m_records[m_size++] = init_record("shrubbery creation", new ShrubberyCreationForm);
        (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
        if (this == &other)
                return *this;
        return (*this);
}

Intern::~Intern()
{
        for (int i = 0; i < m_size; i++)
        {
                delete m_records[i].prototype;
        }
}

AForm *Intern::makeForm(const std::string &type, const std::string &target) const
{
        for (int i = 0; i < m_size; i++)
        {
                if (type == m_records[i].name)
                {
                        std::cout << "Intern creates " << type << "\n";
                        return m_records[i].prototype->clone(target);
                }
        }
        std::cout << "Intern doesn't know how to create " << type << "\n";
        return 0;
}
