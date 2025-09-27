#include "Fixed.h"

Fixed::Fixed() : raw_bits(0)
{
        std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) : raw_bits(other.raw_bits)
{
        std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
        std::cout << "Copy assignment operator called\n";
        if (&other == this)
        {
                return (*this);
        }
        this->raw_bits = other.getRawBits();
        return (*this);
}

Fixed::~Fixed()
{
        std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
        std::cout << "getRawBits member function called\n";
        return this->raw_bits;
}

void Fixed::setRawBits(int const raw)
{
        std::cout << "setRawBits member function called\n";
        raw_bits = raw;
}
