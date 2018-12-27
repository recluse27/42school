/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:27:27 by ale-goff          #+#    #+#             */
/*   Updated: 2018/08/05 23:13:27 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int tab[9][9];

	if (validation(argc, argv) == 1)
	{
		value_tables(argv, tab);
		solve_sudoku(tab, 0);
		print_sudoku(tab);
	}
	else
		ft_putstr("ERROR\n");
	return (0);
}
