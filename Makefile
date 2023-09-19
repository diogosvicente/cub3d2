CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

SRC		= main.c
NAME	= cub3d

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

run: all
	@./$(NAME) maps/1.cub

.PHONY: all clean fclean re run
