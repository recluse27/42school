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

# NAME = get_next_line
# CC = gcc -c
# AR = ar rc
# CFLAGS = -Wall -Werror -Wextra
# HEADER = get_next_line.h
# SRC = *.c

# OBJ=$(SRC:.c=.o)

# all : $(NAME)

# $(NAME) :
# 		make -C libft
# 		@$(CC) -o $(NAME) $(CFLAGS) $(SRC) -LLibft -lft -I $(HEADER)

# clean :
# 		make clean -C libft
# 		/bin/rm -f *~

# fclean : clean
# 		make fclean -C libft
# 		/bin/rm -f $(NAME)

# re : fclean all
NAME = get_next_line
CFLAG = -Wall -Werror -Wextra
HEADER = get_next_line.h
SOURCE = *.c

all : $(NAME)

$(NAME) :
		make -C libft
		gcc -o $(NAME) $(CFLAG) $(SOURCE) -Llibft -lft -I $(HEADER)

clean :
		make clean -C libft
		/bin/rm -f *~

fclean : clean
		make fclean -C libft
		/bin/rm -f $(NAME)

re : fclean all