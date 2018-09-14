NAME = libftprintf.a
CC = gcc -c
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
				$(CC) $(CFLAGS) $(SRC)
				$(AR) $(NAME) $(OBJ)
				ranlib $(NAME)

clean:
				-rm -f $(OBJ)

fclean: clean
				-rm -f $(NAME)

re: fclean all
