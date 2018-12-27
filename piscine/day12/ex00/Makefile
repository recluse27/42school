# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 12:51:55 by vlazuka           #+#    #+#              #
#    Updated: 2018/08/09 21:03:39 by vlazuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror -g

NAME=ft_display_file

all:
	gcc -c $(CFLAGS) *.c
	gcc *.o -o $(NAME)

clean:
	rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
