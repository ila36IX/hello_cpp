#include "Fixed.h"

int main(void)

{
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
        std::cout << Fixed::min(a, b) << std::endl;
        return 0;
}

int _main()
{
        Fixed a(2.2f);
        Fixed b(2);

        std::cout << std::boolalpha;
        std::cout << "a=" << a << " b=" << b << "\n";
        std::cout << "a > b  is " << (a > b) << "\n";
        std::cout << "a < b  is " << (a < b) << "\n";
        std::cout << "a >= b is " << (a >= b) << "\n";
        std::cout << "a <= b is " << (a <= b) << "\n";
        std::cout << "a == b is " << (a == b) << "\n";
        std::cout << "a != b is " << (a != b) << "\n";

        std::cout << "a + b = " << a + b << "\n";
        std::cout << "a - b = " << a - b << "\n";
        std::cout << "a / b = " << a / b << "\n";
        std::cout << "a * b = " << a * b << "\n";
        Fixed n1 = 1;
        Fixed n2 = ++n1;
        Fixed n3 = ++++n2;
        std::cout << "n3 = " << n3 << "\n";
        return (0);
}
