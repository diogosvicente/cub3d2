NAME	= libft.a

SRC	= ft_isalnum.c ft_isprint.c ft_putchar_fd.c ft_strlen.c ft_isalpha.c \
	  ft_memcpy.c ft_putendl_fd.c ft_strncmp.c ft_bzero.c ft_isascii.c \
	  ft_putnbr_fd.c ft_tolower.c ft_isdigit.c ft_memset.c ft_putstr_fd.c \
	  ft_toupper.c ft_strlcpy.c ft_strlcat.c ft_memmove.c ft_strchr.c \
	  ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c ft_strtrim.c\
	  ft_split.c ft_strmapi.c ft_striteri.c ft_strcmp.c\
	  ft_printf.c ft_putchar.c ft_hexnbr.c ft_putnbr.c ft_putstr.c\
	  ft_unsignbr.c ft_strccpy.c ft_joinfree.c ft_strichr.c\
	  get_next_line.c ft_atoi_base.c ft_atoi_long.c ft_isspace.c ft_istrchr.c\
	  ft_trimfree.c\

JJ	= ${SRC:.c=.o}

CC	= cc

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror

AR	= ar rc

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@printf "\033[0;32m#\e[m"

${NAME}: ${JJ}
	@${AR} ${NAME} ${JJ}
	@printf "\033[0;32m Libft OK\e[m\n"

all: ${NAME}

clean:
	@${RM} ${JJ}

fclean: clean
	@${RM} ${NAME}
	@printf "\033[0;33mLIBFT CLEAN\e[m\n"

re: fclean all

norm:
	norminette ft* libft.h

.PHONY: all clean fclean re
