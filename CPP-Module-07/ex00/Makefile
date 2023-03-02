CC			= c++
CXXFLAGS	= -std=c++98 -Werror -Wextra -Wall

NAME		= ex00

SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
