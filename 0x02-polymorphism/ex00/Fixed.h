#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed
{
      private:
        int raw_bits;
        static const int frac_size = 8; // the number of fractional bits

      public:
        Fixed();
        Fixed(const Fixed &);
        Fixed &operator=(const Fixed &);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif /* FIXED_H */
