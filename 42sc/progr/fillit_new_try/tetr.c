/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:01:41 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/05 01:01:54 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include <stdio.h>

typedef struct			s_tetrimino
{
	char				**data;
	char				letter;
	struct s_tetrimino	*next;
}						t_tetrimino;




t_tetrimino			*make_node(t_tetrimino *next, char letter)
{
	t_tetrimino		*new;

	if (!(new = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	new->data = ft_mapalloc(4, 4);
	new->letter = letter;
	new->next = next;
	//new->width = 0;
	//new->height = 0;
	return (new);
}

int						add_node(t_tetrimino **head, t_tetrimino *new_node)
{
	t_tetrimino		*current;

	current = *head;
	if (!head || !*head || !new_node)
		return (-1);
	while (current->next)
		current = current->next;
	new_node->letter = current->letter + 1;
	current->next = new_node;
	return (1);
}

void					erase_list(t_tetrimino **head)
{
	t_tetrimino		*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		ft_mapdel(tmp->data);
		free(tmp);
		tmp = NULL;
	}
	head = NULL;
}

void					del_node(t_tetrimino **node)
{
	ft_mapdel((*node)->data);
	free(*node);
	*node = NULL;
}

void		print_tetr(t_tetrimino *node)
{
	int i;
	int j;

	i = 0;
	while(node->data[i])
	{
		j = 0;
		while (node->data[i][j])
		{
			printf("%c\t", node->data[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_tetrs(t_tetrimino **head)
{
	t_tetrimino *cur;

	cur = *head;
	while (cur->next)
	{
		print_tetr(cur);
		cur = cur->next;
	}
}

int			check_number_of_hashtags(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '#' && line[i] != '.' && line[i] != '\n')
			return (-1);
		//if (line[i] == '#')
		//	++*count_hashtags;
		//if (*count_hashtags > 4)
		//	return (-1);
		++i;
	}
	return (0);
}

int			check_number_of_lines(int *count_lines, char *line)
{
	if (*count_lines != 4)
	{
		if (ft_strlen(line) != 4)
			return (-1);
	}
	if (*count_lines == 4)
	{
		*count_lines = -1;
		//*count_hashtags = 0;
		if (ft_strcmp(line, "") != 0)
			return (-1);
	}
	*count_lines = *count_lines + 1;
	return (0);
}

t_tetrimino		*add_tetrimino(t_tetrimino *list, char *str)
{
	char		**ndata;
	t_tetrimino	*new;
	t_tetrimino	*temp;

	ndata = ft_strsplit(str, '\n');
	if (list == NULL)
	{
		list = malloc(sizeof(t_tetrimino));
		list->data = ndata;
		list->next = NULL;
		list->letter = 'A';
		return (list);
	}
	temp = list;
	new = malloc(sizeof(t_tetrimino));
	new->data = ndata;
	new->next = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->letter = temp->letter + 1;
	return (list);
}


void		adding_to_list(char **input, char **line, int count_lines,
	t_tetrimino **list)
{
	char			*tmp;

	// tmp = ft_strjoin(*input, *line);
	// *input = tmp;
	*input = ft_strjoin(*input, *line);
	if (ft_strcmp(*line, "") != 0)
	{
		// tmp = ft_strjoin(*input, "\n");
		// free(*input);
		// *input = tmp;
		*input = ft_strjoin(*input, "\n");
	}
	if (count_lines == 4)
	{
		*list = add_tetrimino(*list, *input);
		ft_strdel(input);
		*input = ft_strnew(1);
	}
	ft_strdel(line);
}

int		print_tetriminos(t_tetrimino *list)
{
	int	x;
	int	y;
	int	count;

	while (list)
	{
		count = 0;
		y = 0;
		while (list->data[y])
		{
			x = 0;
			while (list->data[y][x])
			{
				//count = check_adjacent_sides(list, x, y, count);
				printf("%c\t", list->data[y][x]);
				++x;
			}
			++y;
			printf("\n");
		}
		// if (count != 6 && count != 8)
			// return (-1);
		printf("\n");
		list = list->next;
	}
	return (1);
}

int main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		int			fd;
		char		*line;
		char 		*input;
		t_tetrimino *list;
		int			count_lines;
		//int			count_hashtags;

		fd = open(argv[1], O_RDONLY);
		count_lines = 0;
		//count_hashtags = 0;
		input = ft_strnew(1);
		list = NULL;
		if (fd == -1)
			return (0);
		while (get_next_line(fd, &line) == 1)
		{
			if (check_number_of_lines(&count_lines, line) == -1 ||\
							check_number_of_hashtags(line) == -1)
				return (0);
			adding_to_list(&input, &line, count_lines, &list);
		}
		
	print_tetriminos(list);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}