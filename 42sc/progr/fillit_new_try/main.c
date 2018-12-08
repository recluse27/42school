/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:50:45 by amagnan           #+#    #+#             */
/*   Updated: 2018/11/05 11:50:46 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int					g_size;

/*
**	This is the start of the function
*/

//int					main(int argc, char **argv)

int					main(int argc, char **argv)
{
	t_tetrimino	*tetriminos;

	g_size = 4;
	tetriminos = NULL;
	if (argc == 2)
	{
		if ((tetriminos = fillit_check(argv[1])) == NULL)
		{
			ft_putstr("error\n");
			return (-1);
		}
		//get_tetriminos(argv[1], &tetriminos);
		//algorithm(tetriminos);
	}
	else
		ft_error("usage: ./fillit source_file\n");
	return (0);
}

/*	0
**	ERRORS :
**
**	File 19 is different
**	File 7 is different because the smallest possible map is 3 and I start at 4
**	File 20 is different because there's only 1 tetrimino
**
**	There's something weird with when I erase the tetrimino and create a new one
**	because when I change g_size from 4 to 3 I segfault everytime
*/ 

int		check_adjacent_sides(t_tetrimino *list, int x, int y, int count)
{
	if (list->piece[y][x] == '#')
	{
		if (x != 3 && list->piece[y][x + 1] == '#')
			++count;
		if (x != 0 && list->piece[y][x - 1] == '#')
			++count;
		if (y != 3 && list->piece[y + 1][x] == '#')
			++count;
		if (y != 0 && list->piece[y - 1][x] == '#')
			++count;
	}
	return (count);
}

int		check_for_tetriminos(t_tetrimino *list)
{
	int	x;
	int	y;
	int	count;

	while (list)
	{
		count = 0;
		y = 0;
		while (list->piece[y])
		{
			x = 0;
			while (list->piece[y][x])
			{
				count = check_adjacent_sides(list, x, y, count);
				++x;
			}
			++y;
		}
		if (count != 6 && count != 8)
			return (-1);
		list = list->next;
	}
	return (1);
}


int			check_number_of_hashtags(int *count_hashtags, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '#' && line[i] != '.' && line[i] != '\n')
			return (-1);
		if (line[i] == '#')
			++*count_hashtags;
		if (*count_hashtags > 4)
			return (-1);
		++i;
	}
	return (0);
}

int			check_number_of_lines(int *count_lines,
	int *count_hashtags, char *line)
{
	if (*count_lines != 4)
	{
		if (ft_strlen(line) != 4)
			return (-1);
	}
	if (*count_lines == 4)
	{
		*count_lines = -1;
		*count_hashtags = 0;
		if (ft_strcmp(line, "") != 0)
			return (-1);
	}
	*count_lines = *count_lines + 1;
	return (0);
}

void		adding_to_list(char **input, char **line, int count_lines,
	t_tetrimino **list)
{
	char			*tmp;

	tmp = ft_strjoin(*input, *line);
	*input = tmp;
	if (ft_strcmp(*line, "") != 0)
	{
		tmp = ft_strjoin(*input, "\n");
		free(*input);
		*input = tmp;
	}
	if (count_lines == 4)
	{
		*list = add_tetrimino(*list, *input);
		ft_strdel(input);
		*input = ft_strnew(1);
	}
	ft_strdel(line);
}

t_tetrimino	*input_check(const int fd, t_tetrimino *list)
{
	char			*line;
	char			*input;
	int				count_lines;
	int				count_hashtags;

	count_lines = 0;
	count_hashtags = 0;
	input = ft_strnew(1);
	list = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (check_number_of_lines(&count_lines, &count_hashtags, line) == -1 ||\
						check_number_of_hashtags(&count_hashtags, line) == -1)
			return (NULL);
		adding_to_list(&input, &line, count_lines, &list);
	}
	if (count_lines != 4)
		return (NULL);
	return (list);
}

t_tetrimino		*add_tetrimino(t_tetrimino *list, char *str)
{
	char		**data;
	t_tetrimino	*new;
	t_tetrimino	*temp;

	data = ft_strsplit(str, '\n');
	if (list == NULL)
	{
		list = malloc(sizeof(t_tetrimino));
		list->piece = data;
		list->next = NULL;
		list->letter = 'A';
		return (list);
	}
	temp = list;
	new = malloc(sizeof(t_tetrimino));
	new->piece = data;
	new->next = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->letter = temp->letter + 1;
	return (list);
}

t_tetrimino		*fillit_check(char *file)
{
	int			fd;
	t_tetrimino	*list;

	list = NULL;
	fd = open(file, O_RDWR);
	if (fd == -1)
		return (NULL);
	if ((list = input_check(fd, list)) == NULL)
		return (NULL);
	if (check_for_tetriminos(list) == -1)
		return (NULL);
	close(fd);
	return (list);
}
