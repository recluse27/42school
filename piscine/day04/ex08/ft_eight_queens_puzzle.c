/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 12:13:33 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/28 21:47:15 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DIFF(a, b) ((a < b) ? (b - a) : (a - b))

int	ft_solve(int n, int col, int *hist)
{
	int i;
	int j;
	int count;

	count = 0;
	if (col == n)
		count++;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < col && !(hist[j] == i) && !(DIFF(hist[j], i) == col - j))
			j++;
		if (j < col)
		{
			i++;
			continue;
		}
		hist[col] = i;
		count += ft_solve(n, col + 1, hist);
		i++;
	}
	return (count);
}

int	ft_eight_queens_puzzle(void)
{
	int hist[8];

	return (ft_solve(8, 0, hist));
}
