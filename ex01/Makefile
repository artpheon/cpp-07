NAME	= ex00
SRC		= main.cpp
OBS		= $(SRC:.cpp=.o)
FLAGS	= -Wall -Wextra -Werror
INC		= -I.
HED		= iter.hpp
CC		= clang++
%.o:	%.cpp
	$(CC) $(INC) $(FLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBS) $(HED)
	$(CC) $(OBS) $(INC) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(OBS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re