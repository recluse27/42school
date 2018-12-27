/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:57:47 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/01 21:02:22 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_sort_ascii(char **val, int nb)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < (nb - 1))
	{
		j = 0;
		while (val[i][j] == val[i + 1][j])
			j++;
		if (val[i][j] > val[i + 1][j])
		{
			tmp = val[i];
			val[i] = val[i + 1];
			val[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

void	ft_print(char **val, int nb)
{
	int i;
	int y;

	if (nb > 1)
	{
		i = 1;
		while (i < nb)
		{
			y = 0;
			while (val[i][y] != '\0')
			{
				ft_putchar(val[i][y]);
				y++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	ft_sort_ascii(argv, argc);
	ft_print(argv, argc);
	return (0);
}
