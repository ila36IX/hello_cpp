#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <ostream>

class Fixed
{
      private:
        int raw_bits;
        static const int frac_size = 8; // the number of fractional bits

      public:
        Fixed();
        Fixed(const int);
        Fixed(const float);
        Fixed(const Fixed &);
        Fixed &operator=(const Fixed &);
        ~Fixed();

        bool operator>(const Fixed &);
        bool operator>=(const Fixed &);
        bool operator<(const Fixed &);
        bool operator<=(const Fixed &);
        bool operator==(const Fixed &);
        bool operator!=(const Fixed &);

        Fixed operator+(const Fixed &);
        Fixed operator-(const Fixed &);
        Fixed operator*(const Fixed &);
        Fixed operator/(const Fixed &);

        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fp);

#endif /* FIXED_H */
