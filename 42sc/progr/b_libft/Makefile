NAME = libft.a
CC = gcc -c
AR = ar rc
W = -Wall -Wextra -Werror
HEADER = libft.h
SRC = *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(W) $(SRC) -I $(HEADER)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
