# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 11:14:20 by vlazuka           #+#    #+#              #
#    Updated: 2018/09/20 15:55:19 by vlazuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = b_printf.a
CC = gcc -c
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
HEADER = printf.h
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
