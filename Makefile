SRC = $(wildcard main.c src/*.c parser/*.c)

OBJ = ${SRC:.c=.o}

CC = cc
FLAGS = -Wall -Wextra -Werror
LIBS_LINUX = -I/usr/include -Imlx_linux -Ilibft
MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -rf
NAME = cub3D
LFT = libft/libft.a
.c.o: 
	${CC} ${FLAGS} ${LIBS_LINUX} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} ${LFT} 
	${CC} ${FLAGS} ${OBJ} ${LFT} ${MLX_LINUX} -o ${NAME}

$(LFT):
	make -C libft
	make -C mlx_linux

all: ${NAME}

clean: 
	@make clean -C libft
	@${RM} ${OBJ}

fclean: clean
	@make clean -C mlx_linux
	@make fclean -C libft
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
