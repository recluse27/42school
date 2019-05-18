/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:30:00 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/14 15:30:01 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

int						get_links(char **data, int i, int j)
{
	int					n;

	n = 0;
	if (data[i][j] == '#')
	{
		if (j < 3 && data[i][j + 1] == '#')
			n++;
		if (j > 0 && data[i][j - 1] == '#')
			n++;
		if (i < 3 && data[i + 1][j] == '#')
			n++;
		if (i > 0 && data[i - 1][j] == '#')
			n++;
	}
	return (n);
}

int						check_piece(t_tetrimino *list)
{
	int					i;
	int					j;
	int					links;

	while (list)
	{
		i = -1;
		links = 0;
		while (list->data[++i])
		{
			j = -1;
			while (list->data[i][++j])
			{
				links += get_links(list->data, i, j);
			}
		}
		if (links != 6 && links != 8)
			return (-1);
		list = list->next;
	}
	return (1);
}

int						check_file(const int fd, int nlines,
	int nhash, t_tetrimino **tetr)
{
	char				*line;
	char				*buff;

	buff = ft_strnew(1);
	while (get_next_line(fd, &line) == 1)
	{
		if (check_line(line, &nlines, &nhash) == -1)
			return (-1);
		else
			buff = ft_update(buff, ft_strjoin(buff, line));
		if (ft_strcmp(line, "") != 0)
			buff = ft_update(buff, ft_strjoin(buff, "\n"));
		if (nlines == 4)
		{
			*tetr = add_tetr(*tetr, buff);
			ft_strdel(&buff);
			buff = ft_strnew(1);
		}
		ft_strdel(&line);
	}
	if (nlines != 4 || check_piece(*tetr) == -1)
		return (-1);
	ft_strdel(&buff);
	close(fd);
	return (1);
}

int						check_line(char *line, int *nlines, int *nhash)
{
	int					i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '#' && line[i] != '.' && line[i] != '\n')
			return (-1);
		if (line[i] == '#')
			(++*nhash);
		if (*nhash > 4)
			return (-1);
		i++;
	}
	if (*nlines == 4)
	{
		if (ft_strcmp(line, "") != 0)
			return (-1);
		*nlines = -1;
		*nhash = 0;
	}
	else if (ft_strlen(line) != 4)
		return (-1);
	(*nlines)++;
	return (1);
}

int						open_file(char *name, t_tetrimino **tetr)
{
	int					fd;
	int					nlines;
	int					nhash;

	fd = open(name, O_RDONLY);
	nlines = 0;
	nhash = 0;
	if (fd == -1)
		return (0);
	return (check_file(fd, nlines, nhash, tetr));
}
