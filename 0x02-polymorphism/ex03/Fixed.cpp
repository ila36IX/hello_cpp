#include "Fixed.h"
#include <cmath>

Fixed::Fixed() : raw_bits(0)
{
        if (log_info)
                std::cout << "Default constructor called\n";
}

Fixed::Fixed(int n) : raw_bits(n << Fixed::frac_size)
{
        if (log_info)
                std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n) : raw_bits(roundf(n * (1 << Fixed::frac_size)))
{
        if (log_info)
                std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &other) : raw_bits(other.raw_bits)
{
        if (log_info)
                std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
        if (log_info)
                std::cout << "Copy assignment operator called\n";
        if (&other == this)
        {
                return (*this);
        }
        this->raw_bits = other.getRawBits();
        return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fp)
{
        os << fp.toFloat();
        return (os);
}

Fixed::~Fixed()
{
        if (log_info)
                std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
        if (log_info)
                std::cout << "getRawBits member function called\n";
        return this->raw_bits;
}

void Fixed::setRawBits(int const raw)
{
        if (log_info)
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

// Comparison
bool Fixed::operator>(const Fixed &other)
{
        return (this->raw_bits > other.raw_bits);
}

bool Fixed::operator>=(const Fixed &other)
{
        return (this->raw_bits >= other.raw_bits);
}

bool Fixed::operator<(const Fixed &other)
{
        return (this->raw_bits < other.raw_bits);
}

bool Fixed::operator<=(const Fixed &other)
{
        return (this->raw_bits <= other.raw_bits);
}

bool Fixed::operator==(const Fixed &other)
{
        return (this->raw_bits == other.raw_bits);
}

bool Fixed::operator!=(const Fixed &other)
{
        return (this->raw_bits != other.raw_bits);
}

// arithmetics
Fixed Fixed::operator+(const Fixed &other)
{
        Fixed a;

        a.setRawBits(this->raw_bits + other.raw_bits);
        return (a);
}

Fixed Fixed::operator-(const Fixed &other)
{
        Fixed a;

        a.setRawBits(this->raw_bits - other.raw_bits);
        return (a);
}

Fixed Fixed::operator*(const Fixed &other)
{
        Fixed a;
        int raw;

        raw = static_cast<long long>(this->raw_bits) * static_cast<long long>(other.raw_bits) >> frac_size;
        a.setRawBits(raw);
        return (a);
}

Fixed Fixed::operator/(const Fixed &other)
{
        Fixed a;
        int raw;

        raw = static_cast<long long>(this->raw_bits << frac_size) / other.raw_bits;
        a.setRawBits(raw);
        return (a);
}

Fixed &Fixed::operator++()
{
        this->raw_bits++;
        return (*this);
}

Fixed &Fixed::operator--()
{
        this->raw_bits--;
        return (*this);
}

Fixed Fixed::operator++(int)
{
        Fixed tmp = *this;

        this->raw_bits++;
        return (tmp);
}

Fixed Fixed::operator--(int)
{
        Fixed tmp = *this;

        this->raw_bits--;
        return (tmp);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
        if (a.getRawBits() < b.getRawBits())
                return (a);
        else
                return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
        if (a.getRawBits() < b.getRawBits())
                return (a);
        else
                return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
        if (a.getRawBits() > b.getRawBits())
                return (a);
        else
                return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
        if (a.getRawBits() > b.getRawBits())
                return (a);
        else
                return (b);
}

bool Fixed::log_info = false;
