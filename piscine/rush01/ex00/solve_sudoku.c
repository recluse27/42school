/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:25:36 by ale-goff          #+#    #+#             */
/*   Updated: 2018/08/05 21:51:45 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		row_missing(int i, int k, int table[9][9])
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (table[i][j] == k)
			return (0);
		j++;
	}
	return (1);
}

int		column_missing(int j, int k, int table[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (table[i][j] == k)
			return (0);
		i++;
	}
	return (1);
}

int		box_missing(int i, int j, int k, int table[9][9])
{
	int row;
	int col;

	row = i - (i % 3);
	col = j - (j % 3);
	i = row;
	while (i < row + 3)
	{
		j = col;
		while (j < col + 3)
		{
			if (table[i][j] == k)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		solve_sudoku(int table[9][9], int position)
{
	int i;
	int j;
	int k;

	if (position == 9 * 9)
		return (1);
	i = position / 9;
	j = position % 9;
	if (table[i][j] != 0)
		return (solve_sudoku(table, position + 1));
	k = 1;
	while (k <= 9)
	{
		if (box_missing(i, j, k, table) &&
				column_missing(j, k, table) && row_missing(i, k, table))
		{
			table[i][j] = k;
			if (solve_sudoku(table, position + 1))
				return (1);
		}
		k++;
	}
	table[i][j] = 0;
	return (0);
}
