SRC = src/*.c 

CC = gcc
FLAGS = -g -std=c99 -lSDL2 -lm
RM = rm -rf
NAME = raycast

${NAME}:
	${CC} ${SRC} ${FLAGS} -o ${NAME}

all: ${NAME}

clean: 
	${RM} ${NAME}
re: clean all

tst: all 
	./${NAME}

.PHONY: all clean re 
