/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:54:21 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/14 15:54:24 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct			s_tetrimino
{
	char				**data;
	char				letter;
	struct s_tetrimino	*next;
}						t_tetrimino;

void					fillit(t_tetrimino *tetr);
void					erase_list(t_tetrimino **head);
void					del_node(t_tetrimino **node);
int						algorithm(char **map, t_tetrimino *tetr);
int						insert_check(char **map, char **data,
									int j_map, int i_map);
char					**clean(char **map, t_tetrimino *tetr,
								int j_map, int i_map);
char					**insert(char **map, t_tetrimino *tetr,
								int j_map, int i_map);
int						ft_lst_size(t_tetrimino *tetr);
void					print_map(char **map);
int						msq(int nb);
char					**create_map(int size);
t_tetrimino				*clean_tetr(t_tetrimino *tetr);
t_tetrimino				*clean_rows(t_tetrimino *tetr);
t_tetrimino				*clean_cols_left(t_tetrimino *tetr);
void					rem_cols_left(t_tetrimino **new,
										t_tetrimino **tetr, int count, int j);
t_tetrimino				*clean_cols_right(t_tetrimino *tetr);
void					rem_cols_right(t_tetrimino **new,
										t_tetrimino **tetr, int count, int j);
void					ft_error(char *str);
int						open_file(char *name, t_tetrimino **tetr);
int						check_file(const int fd, int nlines,
									int nhash, t_tetrimino **tetr);
int						check_piece(t_tetrimino *list);
int						get_links(char **data, int i, int j);
t_tetrimino				*add_tetr(t_tetrimino *tetr, char *buff);
int						add_node(t_tetrimino **head, t_tetrimino *new_node);
t_tetrimino				*make_node(char **ndata, char letter);
int						check_line(char *line, int *nlines, int *nhash);

#endif
