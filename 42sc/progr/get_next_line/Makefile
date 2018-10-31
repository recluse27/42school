# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 13:36:43 by vlazuka           #+#    #+#              #
#    Updated: 2018/10/25 13:39:14 by vlazuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
CC = gcc -c
AR = ar rc
CFLAGS = -Wall -Werror -Wextra
HEADER = get_next_line.h
SRC = *.c

all : $(NAME)

$(NAME) :
		make -C Libft
		gcc -o $(NAME) $(CFLAGS) $(SRC) -LLibft -lft -I $(HEADER)

clean :
		make clean -C Libft
		/bin/rm -f *~

fclean : clean
		make fclean -C Libft
		/bin/rm -f $(NAME)

re : fclean all
