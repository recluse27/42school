#include "libft/libft.h"
#include <stdio.h>

typedef struct			s_tetrimino
{
	char				**data;
	char				letter;
	int					width;
	int					height;
	int					dist_side;
	int					dist_top;
	struct s_tetrimino	*next;
}						t_tetrimino;

typedef	struct				s_map
{
	char					**grid;
	int						size;
}							t_map;

t_map						*make_map(int size);
void						del_map(t_map **map);
void						clean_map(t_map **map, t_tetrimino *node);
void						print_grid(char **grid);
void						algorithm(t_tetrimino *head);
int							fill_grid(t_map *map, t_tetrimino *node);
int							try_piece(t_map *map, t_tetrimino *node);
void						put_piece(t_map *map, t_tetrimino *node);
int							get_links(char **grid, int i, int j);
void						get_properties(t_tetrimino **tetr);
void						get_tetriminos(char *argv, t_tetrimino **head);
void						get_tetri_size(t_tetrimino **tetr);
void						prepare_tetriminos(t_tetrimino **tetr);
void						ft_error(char *str);
void						check_piece(char **grid);
t_tetrimino				*make_node(char **ndata, char letter);
int							add_node(t_tetrimino **head,
										t_tetrimino *new_node);
void						erase_list(t_tetrimino **head);
int							get_piece(t_tetrimino **tetr, int fd,
										char *str, int count);
void						del_node(t_tetrimino **node);
char						**new_tetri(void);
int							move_right(t_tetrimino **tetr);
int							move_down(t_tetrimino **tetr);
int							move_tetrimino(t_tetrimino **tetr);
int							get_offset(t_tetrimino **tetr);
int				check_if_ok(t_tetrimino **tetr, int x);


int					g_size;

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

int						check_p(t_tetrimino *list)
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
		get_properties(&list);
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
				return (-1);
		else
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
	if (nlines != 4 || check_p(*tetr) == -1)
		return (-1);
	close(fd);
	return (1);
}










void				check_piece(char **grid)
{
	int				i;
	int				j;
	int				links;
	int				count;

	i = -1;
	count = 0;
	links = 0;
	while (grid[++i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] != '.' && grid[i][j] != '#')
				ft_error("ERROR");
			else if (grid[i][j] == '#')
			{
				links += get_links(grid, i, j);
				count++;
			}
			j++;
		}
	}
	if (count != 4 || (links != 6 && links != 8))
		ft_error("ERROR");
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

void				clean_map(t_map **map, t_tetrimino *node)
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

int			try_piece(t_map *map, t_tetrimino *node)
{
	int		i;
	int		j;

	i = 0;
	while (node->data[i] && map->grid[i])
	{
		j = 0;
		while (node->data[i][j] && map->grid[i][j])
		{
			if ((node->data[i][j] == '#' && map->grid[i][j] != '.'))
				return (0);
			j++;
		}
		i++;
	}
	put_piece(map, node);
	return (1);
}

void		put_piece(t_map *map, t_tetrimino *node)
{
	int		i;
	int		j;

	i = 0;
	while (node->data[i] && map->grid[i])
	{
		j = 0;
		while (node->data[i][j] && map->grid[i][j])
		{
			if (node->data[i][j] == '#' && map->grid[i][j] == '.')
				map->grid[i][j] = node->letter;
			j++;
		}
		i++;
	}
}


void				get_tetri_size(t_tetrimino **tetr)
{
	int			i;
	int			j;
	int			h;
	int			w;

	h = 0;
	i = 0;
	while ((*tetr)->data[i])
	{
		j = 0;
		w = 0;
		if (ft_strchr((*tetr)->data[i], '#'))
			h++;
		while ((*tetr)->data[i][j])
		{
			if ((*tetr)->data[i][j] == '#')
				w++;
			j++;
		}
		if (w > (*tetr)->width)
			(*tetr)->width = w;
		i++;
	}
	(*tetr)->height = h;
}

void				prepare_tetriminos(t_tetrimino **tetr)
{
	int			i;
	int			j;

	i = 0;
	while ((*tetr)->data[i])
	{
		j = 0;
		while ((*tetr)->data[i][j])
		{
			if ((*tetr)->data[i][j] == '#')
			{
				(*tetr)->data[i][j] = '.';
				(*tetr)->data[i - (*tetr)->dist_top]
				[j - (*tetr)->dist_side] = '#';
			}
			j++;
		}
		i++;
	}
	get_tetri_size(tetr);
}

int					get_piece(t_tetrimino **tetr, int fd,
	char *str, int count)
{
	int				i;
	int				x;

	i = 0;
	while (i < 4 && (x = get_next_line(fd, &str) > 0))
	{
		if (ft_strlen(str) != 4 || count > 26)
			ft_error("ERROR");
		(*tetr)->data[i++] = ft_strdup(str);
	}
	(*tetr)->data[i] = NULL;
	check_piece((*tetr)->data);
	get_properties(tetr);
	return (x);
}

void				ft_error(char *str)
{
	if (ft_strcmp("USAGE", str) == 0)
	{
		ft_putstr_fd("usage: ./fillit file_name\n", 2);
		exit(-1);
	}
	else if (ft_strcmp("ERROR", str) == 0)
	{
		ft_putstr_fd("error\n", 2);
		exit(-1);
	}
}

void				get_tetriminos(char *argv, t_tetrimino **head)
{
	int				fd;
	char			*str;
	t_tetrimino		*tetr;
	int				x;
	int				count;

	count = 0;
	str = NULL;
	x = 1;
	fd = open(argv, O_RDONLY);
	while (x > 0)
	{
		tetr = make_node(NULL, 'A' + count);
		count++;
		x = get_piece(&tetr, fd, str, count);
		if (!(*head))
			(*head = tetr);
		else
			add_node(head, tetr);
		x = get_next_line(fd, &str);
		if (ft_strcmp(str, ""))
			ft_error("ERROR");
	}
	if (count == 1)
		ft_error("ERROR");
	close(fd);
}

void				get_properties(t_tetrimino **tetr)
{
	int			i;
	int			j;
	int			min_width;

	i = 0;
	min_width = 4;
	while ((*tetr)->data[i] && (!(ft_strchr((*tetr)->data[i], '#'))))
		i++;
	(*tetr)->dist_top = i;
	i = 0;
	while ((*tetr)->data[i])
	{
		j = 0;
		while ((*tetr)->data[i][j])
		{
			if ((*tetr)->data[i][j] == '#')
				break ;
			j++;
		}
		if (min_width > j)
			min_width = j;
		i++;
	}
	(*tetr)->dist_side = min_width;
	prepare_tetriminos(tetr);
}

int				move_tetrimino(t_tetrimino **tetr)
{
	if (move_right(tetr) == 0)
		if (move_down(tetr) == 0)
			return (0);
	return (1);
}

int				move_right(t_tetrimino **tetr)
{
	int			i;
	int			j;
	char		**new_piece;

	new_piece = new_tetri();
	if (check_if_ok(tetr, 1) == 0)
		return (0);
	i = -1;
	while ((*tetr)->data[++i])
	{
		j = -1;
		while ((*tetr)->data[i][++j])
		{
			if ((*tetr)->data[i][j] == '#')
			{
				new_piece[i][j + 1] = '#';
				(*tetr)->data[i][j] = '.';
			}
		}
	}
	ft_mapdel((*tetr)->data);
	(*tetr)->data = new_piece;
	return (1);
}

int				move_down(t_tetrimino **tetr)
{
	int			i;
	int			j;
	int			min_offset;
	char		**new_piece;

	new_piece = new_tetri();
	if (check_if_ok(tetr, 0) == 0)
		return (0);
	min_offset = get_offset(tetr);
	i = -1;
	while ((*tetr)->data[++i])
	{
		j = -1;
		while ((*tetr)->data[i][++j])
		{
			if ((*tetr)->data[i][j] == '#')
			{
				new_piece[i + 1][j - min_offset] = '#';
				(*tetr)->data[i][j] = '.';
			}
		}
	}
	ft_mapdel((*tetr)->data);
	(*tetr)->data = new_piece;
	return (1);
}

int				check_if_ok(t_tetrimino **tetr, int x)
{
	int			i;
	int			j;

	i = -1;
	if (x == 1)
	{
		while ((*tetr)->data[++i])
		{
			j = -1;
			while ((*tetr)->data[i][++j])
				if ((*tetr)->data[i][j] == '#' && j == g_size - 1)
					return (0);
		}
	}
	else
	{
		while ((*tetr)->data[++i])
		{
			j = -1;
			while ((*tetr)->data[i][++j])
				if ((*tetr)->data[i][j] == '#' && i == g_size - 1)
					return (0);
		}
	}
	return (1);
}

char			**new_tetri(void)
{
	char		**new;
	int			i;
	int			j;
	int			size;

	size = (g_size < 4) ? 4 : g_size;
	i = 0;
	new = ft_mapalloc(size, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			new[i][j] = '.';
			j++;
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}

int						main(int argc, char *argv[])
{
	t_tetrimino			*tetr;

	tetr = NULL;
	g_size = 2;
	if (argc == 2)
	{
		if (open_file(argv[1], &tetr) == 1)
		{
			// print_tetriminos(tetr);
			algorithm(tetr);
		}
		else
			ft_error("ERROR");
	}
	else
		ft_error("USAGE");
	return (0);
}