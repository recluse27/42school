/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:34:30 by ale-goff          #+#    #+#             */
/*   Updated: 2018/08/05 21:41:02 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_H
# define FT_SUDOKU_H

# include <unistd.h>

int		row_missing(int i, int k, int table[9][9]);
int		column_missing(int j, int k, int table[9][9]);
int		box_missing(int i, int j, int k, int table[9][9]);
void	print_sudoku(int tab[9][9]);
void	value_tables(char **argv, int table[9][9]);
int		solve_sudoku(int table[9][9], int position);
int		box_missing(int i, int j, int k, int table[9][9]);
int		len(char *str);
int		is_range(char c);
void	ft_putstr(char *str);
int		validation(int argc, char **argv);
#endif
