CC			= c++
CXXFLAGS	= -Wall -Werror -Wextra --std=c++98

NAME		= ex00

SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
