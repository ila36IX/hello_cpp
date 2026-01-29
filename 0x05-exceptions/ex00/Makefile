CPPFLAGS  = -Wall -Wextra -Werror -g3 -ggdb3 -std=c++98
SRC_FILES = Bureaucrat.cpp  main.cpp
SRC_OBJ   = $(SRC_FILES:%.cpp=%.o)
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
