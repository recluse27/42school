/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:29:44 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/14 15:29:46 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

t_tetrimino		*add_tetr(t_tetrimino *tetr, char *buff)
{
	char		**ndata;
	t_tetrimino	*new;

	ndata = ft_strsplit(buff, '\n');
	if (tetr == NULL)
		return (make_node(ndata, 'A'));
	new = make_node(ndata, 'A');
	add_node(&tetr, new);
	return (tetr);
}

t_tetrimino		*clean_tetr(t_tetrimino *tetr)
{
	int			count;
	t_tetrimino	*new;
	t_tetrimino *tmp;

	count = 0;
	tmp = tetr;
	new = clean_rows(tetr);
	while (count != 3)
	{
		new = clean_cols_right(new);
		new = clean_cols_left(new);
		count++;
	}
	erase_list(&tmp);
	return (new);
}

char			**insert(char **map, t_tetrimino *tetr, int j_map, int i_map)
{
	int			i_data;
	int			j_data;

	j_data = 0;
	while (tetr->data[j_data])
	{
		i_data = 0;
		while (tetr->data[j_data][i_data])
		{
			if (tetr->data[j_data][i_data] != '.')
				map[j_map + j_data][i_map + i_data] = tetr->letter;
			i_data++;
		}
		j_data++;
	}
	return (map);
}

char			**clean(char **map, t_tetrimino *tetr, int j_map, int i_map)
{
	int			i_data;
	int			j_data;

	j_data = 0;
	while (tetr->data[j_data])
	{
		i_data = 0;
		while (tetr->data[j_data][i_data])
		{
			if (tetr->data[j_data][i_data] != '.')
				map[j_map + j_data][i_map + i_data] = '.';
			i_data++;
		}
		j_data++;
	}
	return (map);
}

t_tetrimino		*clean_rows(t_tetrimino *tetr)
{
	int			i;
	char		*str;
	t_tetrimino	*new;

	new = NULL;
	while (tetr)
	{
		i = 0;
		str = ft_strnew(1);
		while (tetr->data[i])
		{
			if (ft_strcmp(tetr->data[i], "....") != 0)
			{
				str = ft_update(str, ft_strjoin(str, tetr->data[i]));
				str = ft_update(str, ft_strjoin(str, "\n"));
			}
			++i;
		}
		new = add_tetr(new, str);
		free(str);
		tetr = tetr->next;
	}
	return (new);
}
