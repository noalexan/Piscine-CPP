CC = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98

SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

NAME = ex06

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
