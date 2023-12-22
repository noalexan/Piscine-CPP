CC=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

NAME=btc

SRC= main.cpp BitcoinExchange.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
