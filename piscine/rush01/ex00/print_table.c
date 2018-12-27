/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:30:24 by ale-goff          #+#    #+#             */
/*   Updated: 2018/08/05 22:02:56 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_sudoku(int tab[9][9])
{
	int		i;
	int		j;
	char	item;

	j = 0;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			item = tab[i][j] + '0';
			write(1, &item, 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	value_tables(char **argv, int table[9][9])
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				table[i - 1][j] = 0;
			else
				table[i - 1][j] = argv[i][j] - '0';
			j++;
		}
		i++;
	}
}
