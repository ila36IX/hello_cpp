CPPFLAGS  = -Wall -Wextra -Werror -std=c++98
SRC_FILES = Contact.cpp  main.cpp  PhoneBook.cpp  utils.cpp
SRC_OBJ   = $(SRC_FILES:%.cpp=%.o)
NAME      = a.out
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
