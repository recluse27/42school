/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:29:53 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/14 15:29:54 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

int				algorithm(char **map, t_tetrimino *tetr)
{
	int			i;
	int			j;

	j = 0;
	if (!tetr)
		return (1);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (insert_check(map, tetr->data, j, i) == 1)
			{
				map = insert(map, tetr, j, i);
				if (algorithm(map, tetr->next) == 0)
					map = clean(map, tetr, j, i);
				else
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void			rem_cols_right(t_tetrimino **new,
	t_tetrimino **tetr, int count, int j)
{
	char		*temp;
	char		*buff;
	int			i;

	temp = ft_strnew(1);
	if (count == j)
	{
		i = 0;
		while (i < j)
		{
			buff = ft_strsub((*tetr)->data[i], 0,
				(ft_strlen((*tetr)->data[i]) - 1));
			temp = ft_update(temp, ft_strjoin(temp, buff));
			temp = ft_update(temp, ft_strjoin(temp, "\n"));
			free(buff);
			i++;
		}
	}
	else
		temp = ft_update(temp, ft_strcon((*tetr)->data, "\n"));
	*new = add_tetr(*new, temp);
	free(temp);
}

t_tetrimino		*clean_cols_right(t_tetrimino *tetr)
{
	int			i;
	int			j;
	int			count;
	t_tetrimino	*new;
	t_tetrimino *tmp;

	new = NULL;
	tmp = tetr;
	while (tetr)
	{
		j = 0;
		i = ft_strlen(tetr->data[j]);
		count = 0;
		while (tetr->data[j])
		{
			if (tetr->data[j][i - 1] == '.')
				count++;
			j++;
		}
		rem_cols_right(&new, &tetr, count, j);
		tetr = tetr->next;
	}
	erase_list(&tmp);
	return (new);
}

void			rem_cols_left(t_tetrimino **new,
	t_tetrimino **tetr, int count, int j)
{
	char		*temp;
	char		*buff;
	int			i;

	temp = ft_strnew(1);
	if (count == j)
	{
		i = 0;
		while (i < j)
		{
			buff = ft_strsub((*tetr)->data[i], 1,
				(ft_strlen((*tetr)->data[i]) - 1));
			temp = ft_update(temp, ft_strjoin(temp, buff));
			temp = ft_update(temp, ft_strjoin(temp, "\n"));
			free(buff);
			i++;
		}
	}
	else
		temp = ft_update(temp, ft_strcon((*tetr)->data, "\n"));
	*new = add_tetr(*new, temp);
	free(temp);
}

t_tetrimino		*clean_cols_left(t_tetrimino *tetr)
{
	int			i;
	int			j;
	int			count;
	t_tetrimino	*tmp;
	t_tetrimino	*new;

	new = NULL;
	tmp = tetr;
	while (tetr)
	{
		j = 0;
		i = ft_strlen(tetr->data[j]);
		count = 0;
		while (tetr->data[j])
		{
			if (tetr->data[j][0] == '.')
				count++;
			j++;
		}
		rem_cols_left(&new, &tetr, count, j);
		tetr = tetr->next;
	}
	erase_list(&tmp);
	return (new);
}
