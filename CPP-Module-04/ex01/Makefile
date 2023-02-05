CC = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98

SRC = main.cpp Animal.cpp WrongAnimal.cpp Cat.cpp WrongCat.cpp Dog.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)

NAME = ex01

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
