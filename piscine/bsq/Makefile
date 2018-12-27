# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 23:27:29 by vlazuka           #+#    #+#              #
#    Updated: 2018/08/15 23:41:07 by vlazuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SOURCES = srcs/*.c
HEADER = srcs/*.h
FLAGS = -Wall -Wextra -Werror
OUTPUT = *.o

all:
	gcc $(FLAGS) $(SOURCES) -I $(HEADER) -o $(NAME)

clean:
		/bin/rm -f
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all
