# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 12:51:55 by vlazuka           #+#    #+#              #
#    Updated: 2018/08/09 23:27:58 by vlazuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Werror -Wall -Wextra -g
LDFLAGS=
NAME=ft_tail
SRC=ft_tail.c \
	ft_strlen.c \
	ft_strncpy.c \
	error.c \
	main.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
