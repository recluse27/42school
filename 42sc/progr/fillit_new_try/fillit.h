/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:25:39 by amagnan           #+#    #+#             */
/*   Updated: 2018/11/05 11:25:43 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
/*
typedef	struct				s_tetriminos
{
	char					**piece;
	char					letter;
	int						width;
	int						height;
	int						dist_side;
	int						dist_top;
	struct s_tetriminos		*next;
}							t_tetriminos;
*/
typedef struct			s_tetrimino
{
	char				**piece;
	char				letter;
	struct s_tetrimino	*next;
}						t_tetrimino;

// typedef	struct				s_map
// {
// 	char					**grid;
// 	int						size;
// }							t_map;

int							g_size;

// t_map						*make_map(int size);
// void						del_map(t_map **map);
// void						clean_map(t_map **map, t_tetrimino *node);
// void						print_grid(char **grid);
// void						algorithm(t_tetrimino *head);
// int							fill_grid(t_map *map, t_tetrimino *node);
// int							try_piece(t_map *map, t_tetrimino *node);
// void						put_piece(t_map *map, t_tetrimino *node);
// int							get_links(char **grid, int i, int j);
// void						get_properties(t_tetrimino **tetr);
// void						get_tetriminos(char *argv, t_tetrimino **head);
// void						get_tetri_size(t_tetrimino **tetr);
// void						prepare_tetriminos(t_tetrimino **tetr);
// void						ft_error(char *str);
// void						check_piece(char **grid);
// t_tetrimino					*make_node(t_tetrimino *next, char letter);
// int							add_node(t_tetrimino **head,
// 										t_tetrimino *new_node);
// void						erase_list(t_tetrimino **head);
// int							get_piece(t_tetrimino **tetr, int fd,
// 										char *str, int count);
// void						del_node(t_tetrimino **node);
// char						**new_tetri(void);
// int							move_right(t_tetrimino **tetr);
// int							move_down(t_tetrimino **tetr);
// int							move_tetrimino(t_tetrimino **tetr);
// int							get_offset(t_tetrimino **tetr);

#endif
