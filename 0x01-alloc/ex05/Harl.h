#ifndef HARL_H
#define HARL_H

#include <functional>
#include <iostream>
#include <string>

#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))

class Harl
{
      private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

      public:
        Harl();
        void complain(std::string level);
};

#endif // !HARL_H
