/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:26:10 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/14 15:26:11 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

char		**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	map = ft_mapalloc(size, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int			msq(int nb)
{
	int		size;

	nb = nb * 4;
	size = 2;
	while (size * size < nb)
		size++;
	return (size);
}

void		print_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			insert_check(char **map, char **data, int j_map, int i_map)
{
	int		i_data;
	int		j_data;

	j_data = 0;
	while (data[j_data])
	{
		if (map[j_map + j_data] == 0)
			return (-1);
		i_data = 0;
		while (data[j_data][i_data])
		{
			if (map[j_map + j_data][i_map + i_data] == 0)
				return (-1);
			if (data[j_data][i_data] != '.' &&
			map[j_map + j_data][i_map + i_data] != '.')
				return (-1);
			i_data++;
		}
		j_data++;
	}
	return (1);
}
