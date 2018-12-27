# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/11 16:04:56 by vlazuka           #+#    #+#              #
#    Updated: 2018/08/11 16:41:05 by vlazuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror -g

NAME=colle-2

all:
		gcc -c $(CFLAGS) *.c
		gcc *.o -o $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
