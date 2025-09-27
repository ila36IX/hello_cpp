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
        friend std::ostream &operator<<(std::ostream &os, const Fixed &fp);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

#endif /* FIXED_H */
