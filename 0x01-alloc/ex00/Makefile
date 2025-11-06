CPPFLAGS  = -Wall -Wextra -Werror -std=c++98
SRC_FILES = main.cpp  newZombie.cpp  randomChump.cpp  Zombie.cpp
SRC_OBJ   = $(SRC_FILES:%.cpp=%.o)
NAME      = zombie
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
