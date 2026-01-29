#include "Bureaucrat.h"

void init_bureaucrat(const char *name, int grade)
{
        try
        {
                Bureaucrat bureaucrat(name, grade);
                std::cout << bureaucrat << "\n";
        }
        catch (std::exception &e)
        {
                std::cout << e.what() << "\n";
        }
}

int main()
{
        std::cout << "----- Just good -----\n";
        init_bureaucrat("B1", 150);
        init_bureaucrat("B2", 1);
        init_bureaucrat("B3", 80);

        std::cout << "\n----- To high -----\n";
        init_bureaucrat("B4", 0);
        init_bureaucrat("B5", -1);

        std::cout << "\n----- To low -----\n";
        init_bureaucrat("B4", 151);
        init_bureaucrat("B5", 1337);

        std::cout << "\n----- decr -----\n";
        Bureaucrat low("LOW", 148);

        for (int i = 0; i < 5; i++)
        {
                try
                {
                        low.decr();
                        std::cout << low << "\n";
                }
                catch (std::exception &e)
                {
                        std::cout << e.what() << "\n";
                }
        }

        std::cout << "\n----- incr -----\n";
        Bureaucrat high("HIGH", 3);

        for (int i = 0; i < 5; i++)
        {
                try
                {
                        high.incr();
                        std::cout << high << "\n";
                }
                catch (std::exception &e)
                {
                        std::cout << e.what() << "\n";
                }
        }
}
