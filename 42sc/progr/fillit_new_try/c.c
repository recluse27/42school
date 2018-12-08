#include "libft/libft.h"
#include <stdio.h>

typedef struct			s_tetrimino
{
	char				**data;
	char				letter;
	struct s_tetrimino	*next;
}						t_tetrimino;

typedef	struct				s_map
{
	char					**grid;
	int						size;
}							t_map;

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

t_tetrimino				*make_node(char **ndata, char letter)
{
	t_tetrimino			*new;
	
	if (!(new = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	new->data= ndata;
	new->letter = letter;
	new->next = NULL;
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

t_tetrimino				*add_tetr(t_tetrimino *tetr, char *buff)
{
	char				**ndata;
	t_tetrimino			*new;

	ndata = ft_strsplit(buff, '\n');
	if (tetr == NULL)
		return (make_node(ndata, 'A'));
	new = make_node(ndata, 'A');
	add_node(&tetr, new);
	return (tetr);
}

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







int						print_tetriminos(t_tetrimino *tetr)
{
	int					x;
	int					y;
	int					count;

	while (tetr)
	{
		count = 0;
		y = 0;
		while (tetr->data[y])
		{
			x = 0;
			while (tetr->data[y][x])
			{
				printf("%c\t", tetr->data[y][x]);
				++x;
			}
			++y;
			printf("\n");
		}
		printf("\n");
		tetr = tetr->next;
	}
	return (1);
}







int						open_file(char *name, t_tetrimino **tetr)
{
	int					fd;
	char				*line;
	char				*buff;
	int					nlines;
	int					nhash;

	fd = open(name, O_RDONLY);
	nlines = 0;
	nhash = 0;
	buff = ft_strnew(1);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (check_line(line, &nlines, &nhash) == -1)
			{
				// printf("%s\n", "Error!");
				return (-1);
			}
		else
			// printf("%s\n", line);
			buff = ft_strjoin(buff, line);
			if (ft_strcmp(line, "") != 0)
				buff = ft_strjoin(buff, "\n");
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
	// print_tetriminos(tetr);
	close(fd);
	return (1);
}











t_map				*make_map(int size)
{
	t_map			*map;
	int				i;
	int				j;

	i = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->grid = ft_mapalloc(size, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map->grid[i][j] = '.';
			j++;
		}
		i++;
	}
	map->grid[i] = NULL;
	map->size = size;
	return (map);
}

void				del_map(t_map **map)
{
	ft_mapdel((*map)->grid);
	free(*map);
	*map = NULL;
}

void				clean_map(t_map **map, t_tetriminos *node)
{
	int				i;
	int				j;

	i = 0;
	while ((*map)->grid[i])
	{
		j = 0;
		while ((*map)->grid[i][j])
		{
			if ((*map)->grid[i][j] == node->letter)
				(*map)->grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

void				print_grid(char **grid)
{
	int				i;

	i = -1;
	while (grid[++i])
		ft_putendl(grid[i]);
}





int			get_offset(t_tetrimino **tetr)
{
	int			i;
	int			j;
	int			offset;
	int			min_offset;

	i = -1;
	min_offset = 4;
	while ((*tetr)->data[++i])
	{
		j = -1;
		offset = 0;
		while ((*tetr)->data[i][++j])
		{
			if ((*tetr)->data[i][j] == '#')
				break ;
			else
				offset++;
		}
		if (offset < min_offset)
			min_offset = offset;
	}
	return (min_offset);
}


void		algorithm(t_tetrimino *head)
{
	t_map	*map;
	int		g_size;

	g_size = 2;
	map = make_map(g_size);
	if (fill_grid(map, head) == 0)
	{
		del_map(&map);
		g_size++;
		algorithm(head);
	}
	else
	{
		print_grid(map->grid);
		del_map(&map);
		erase_list(&head);
	}
}


int			fill_grid(t_map *map, t_tetrimino *node)
{
	int		x;

	x = 1;
	if (!node)
		return (1);
	while (x == 1)
	{
		if (try_piece(map, node) == 1)
		{
			if (fill_grid(map, node->next) == 1)
				return (1);
		}
		clean_map(&map, node);
		x = move_tetrimino(&node);
	}
	get_properties(&node);
	return (0);
}

/*
**	In this function first we make sure we can fit the
**	entire tetromino in the map at the current location.
**	If we can't the function will return 0 and we will
**	try again at the next coordinate. If we can we call
**	put_piece, which is going to add the tetromino on
**	the map.
*/

int			try_piece(t_map *map, t_tetrimino *node)
{
	int		i;
	int		j;

	i = 0;
	while (node->data[i])
	{
		j = 0;
		while (node->data[i][j])
		{
			if (!map->grid[i][j] || (node->data[i][j] == '#' && map->grid[i][j] != '.'))
				return (0);
			j++;
		}
		i++;
	}
	put_piece(map, node);
	return (1);
}

/*
**	Puts the tetromino on the map.
*/

void		put_piece(t_map *map, t_tetriminos *node)
{
	int		i;
	int		j;

	i = 0;
	while (node->data[i])
	{
		j = 0;
		while (node->data[i][j])
		{
			if (node->data[i][j] == '#' && map->grid[i][j] == '.')
				map->grid[i][j] = node->letter;
			j++;
		}
		i++;
	}
}























int						main(int argc, char *argv[])
{
	t_tetrimino			*tetr;

	tetr = NULL;
	if (argc == 2)
	{
		if (open_file(argv[1], &tetr) == 1)
		{
			print_tetriminos(tetr);
			algorithm(tetr);
		}
		else
			ft_putstr("error\n")
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}