CPPFLAGS  = -Wall -Wextra -Werror -Wno-shadow -O0 -g3 -ggdb3 -std=c++98
SRC_OBJ   = $(SRC_FILES:%.cpp=%.o)
SRC_FILES = ClapTrap.cpp  DiamondTrap.cpp  FragTrap.cpp  main.cpp  ScavTrap.cpp
NAME      = runme
CXX       = c++

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CXX) $(SRC_OBJ) -o $(NAME)

clean: 
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(SRC_OBJ)
