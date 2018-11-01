# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 11:14:20 by vlazuka           #+#    #+#              #
#    Updated: 2018/09/23 16:38:01 by vlazuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = b_ls.a
CC = gcc -c
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
HEADER = ls.h
SRC = *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
				$(CC) $(CFLAGS) $(SRC) -I $(HEADER)

clean:
				@rm -f $(OBJ)

fclean: clean
				@rm -f $(NAME)

re: fclean all
