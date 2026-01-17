#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain
{
      private:
        std::string ideas[100];

      public:
        Brain(void);
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();
};

#endif
