#include "libft/libft.h"
#include <stdio.h>

typedef struct			s_tetrimino
{
	char				**data;
	char				letter;
	struct s_tetrimino	*next;
}						t_tetrimino;
/*
int			check_width_symb(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '#' && line[i] != '.' && line[i] != '\n')
			return (0);
		//if (line[i] == '#')
		//	++*count_hashtags;
		//if (*count_hashtags > 4)
		//	return (-1);
		i++;
	}
	if (i == 1 && line[0] == '\n')
		return (1);
	if (i != 3 && i != 4)
		return (0);
	return (1);
}

int			check_lines(int *count_lines, char *line)
{
	if (*count_lines != 4)
	{
		if (ft_strlen(line) != 4)
			return (0);
	}
	if (*count_lines == 4)
	{
		*count_lines = -1;
		// *count_hashtags = 0;
		if (ft_strcmp(line, "") != 0)
			return (0);
	}
	*count_lines = *count_lines + 1;
	return (1);
}
*/


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



int		check_adjacent_sides(t_tetrimino *list, int x, int y, int count)
{
	if (list->data[y][x] == '#')
	{
		if (x != 3 && list->data[y][x + 1] == '#')
			++count;
		if (x != 0 && list->data[y][x - 1] == '#')
			++count;
		if (y != 3 && list->data[y + 1][x] == '#')
			++count;
		if (y != 0 && list->data[y - 1][x] == '#')
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
		while (list->data[y])
		{
			x = 0;
			while (list->data[y][x])
			{
				count = check_adjacent_sides(list, x, y, count);
				printf("%c\t", list->data[y][x]);
				++x;
			}
			++y;
			printf("\n");
		}
		if (count != 6 && count != 8)
			return (-1);
		list = list->next;
	}
	return (1);
}

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

int					get_piece(t_tetrimino **tetr, int fd,
	char *str, int count)
{
	int				i;
	int				x;

	i = 0;
	// while (i < 4 && (x = get_next_line(fd, &str) > 0))
	while (i < 4)
	{
		//if (ft_strlen(str) != 4 || count > 26)
		//	ft_error("ERROR");
		(*tetr)->data[i++] = ft_strdup(str);
	}
	(*tetr)->data[i] = NULL;
//	check_piece((*tetr)->piece);
//	get_properties(tetr);
	return (x);
} 

t_tetrimino		*fillit_check(char *file, t_tetrimino **head)
{
	int			fd;
	char		*line;
	t_tetrimino	*list;
	int			count;
	char		*input;
	int 		nlines;
	int			count_lines;
	int			count_hashtags;

	count_lines = 0;
	count_hashtags = 0;
	list = NULL;
	input = ft_strnew(1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	nlines = 0;
	count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		printf("Hhh%s/n", line);
		// if (check_width_symb(line) == 0 || check_lines(&nlines, line) == 0)
		// 	return (NULL);
		if (check_number_of_lines(&count_lines, &count_hashtags, line) == -1 ||\
			check_number_of_hashtags(&count_hashtags, line) == -1)
			return (NULL);
		list = make_node(NULL, 'A' + count);
		count++;
		// get_piece(&list, fd, line, count);
		list->data[count % 4] = ft_strdup(line);
		//adding_to_list(&input, &line, count_lines, &list);
		if (!(*head))
			(*head = list);
		else
			add_node(head, list);
	}
	// if (nlines != 4 || check_for_tetriminos(list) == -1)
	if (count_lines != 4 || check_for_tetriminos(list) == -1)
		return (NULL);
	close(fd);
	return (list);
}

t_tetrimino		*add_tetrimino(t_tetrimino *list, char *str)
{
	char		**data1;
	t_tetrimino	*new;
	t_tetrimino	*temp;

	data1 = ft_strsplit(str, '\n');
	if (list == NULL)
	{
		list = malloc(sizeof(t_tetrimino));
		list->data = data1;
		list->next = NULL;
		list->letter = 'A';
		return (list);
	}
	temp = list;
	new = malloc(sizeof(t_tetrimino));
	new->data = data1;
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



int		main(int argc, char **argv)
{
	t_tetrimino		*tetr;
	//t_tetrimino		*list;

	tetr = NULL;
	if (argc == 2)
	{
		if (fillit_check(argv[1], &tetr) == NULL)
		{
			ft_putstr("error\n");
			return (-1);
		}
		//get_tetriminos(argv[1], &tetriminos);
		//algorithm(tetriminos);
	}
	check_for_tetriminos(list);
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
