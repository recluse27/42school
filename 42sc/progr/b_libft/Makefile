NAME = libft.a
CC = gcc -c
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
HEADER = libft.h
SRC = *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
				@$(CC) $(CFLAGS) $(SRC) -I $(HEADER)
				@$(AR) $(NAME) $(OBJ)
				@ranlib $(NAME)

clean:
				@rm -f $(OBJ)

fclean: clean
				@rm -f $(NAME)

re: fclean all
