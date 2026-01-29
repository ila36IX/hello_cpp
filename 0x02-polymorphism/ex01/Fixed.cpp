#include "Fixed.h"
#include <cmath>

Fixed::Fixed() : raw_bits(0)
{
        std::cout << "Default constructor called\n";
}

Fixed::Fixed(int n) : raw_bits(n << Fixed::frac_size)
{
        std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n) : raw_bits(roundf(n * (1 << Fixed::frac_size)))
{
        std::cout << "Float constructor called\n";
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


std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
        os << fp.toFloat();
        return (os);
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

float Fixed::toFloat(void) const
{
        return ((float)raw_bits / (1 << frac_size));
}

int Fixed::toInt(void) const
{
        return (raw_bits >> frac_size);
}
