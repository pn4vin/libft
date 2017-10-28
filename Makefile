NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c

SOURCES = ${wildcard ft_*.c}
OBJECTS = ${SOURCES:.c=.o} 

all: ${NAME}

${NAME}: ${OBJECTS}
	ar -rcs ${NAME} $?

ft_strlen.o:
	${CC} ${FLAGS} ft_strlen.c -I .

.PHONY: clean fclean re

clean:
	@ /bin/rm -f *.o

fclean: clean
	@ /bin/rm -f ${NAME}

re: fclean all

