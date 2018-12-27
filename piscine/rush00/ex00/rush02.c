/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:57:28 by dfan              #+#    #+#             */
/*   Updated: 2018/07/28 12:41:41 by dfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

char	get_corner(char corners[], int row_idx, int col_idx)
{
	if (col_idx == 0)
	{
		return (corners[(row_idx == 0) ? 0 : 2]);
	}
	else
	{
		return (corners[(row_idx == 0) ? 1 : 3]);
	}
}

void	rush_iter(int width, int height, char corners[], char sides[])
{
	int		i;
	int		j;
	char	corner;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			corner = get_corner(corners, i, j);
			if (j == 0 || (j > 0 && j == width - 1))
			{
				ft_putchar((i == 0 || i == height - 1) ? corner : sides[1]);
			}
			else
			{
				ft_putchar((i == 0 || i == height - 1) ? sides[0] : ' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	rush(int width, int height)
{
	char corners[4];
	char sides[2];

	corners[0] = 'A';
	corners[1] = 'A';
	corners[2] = 'C';
	corners[3] = 'C';
	sides[0] = 'B';
	sides[1] = 'B';
	rush_iter(width, height, corners, sides);
}
