/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:21:15 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/14 15:43:23 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

void			ft_error(char *str)
{
	if (ft_strcmp("USAGE", str) == 0)
	{
		ft_putstr_fd("usage: ./fillit source_name\n", 2);
		exit(-1);
	}
	else if (ft_strcmp("ERROR", str) == 0)
	{
		ft_putstr_fd("error\n", 2);
		exit(-1);
	}
}

void			fillit(t_tetrimino *tetr)
{
	int			size;
	char		**map;

	tetr = clean_tetr(tetr);
	size = msq(ft_lst_size(tetr));
	map = create_map(size);
	while (algorithm(map, tetr) == 0)
	{
		ft_mapdel(map);
		map = create_map(++size);
	}
	print_map(map);
	ft_mapdel(map);
	erase_list(&tetr);
}

int				main(int argc, char *argv[])
{
	t_tetrimino	*tetr;

	tetr = NULL;
	if (argc == 2)
	{
		if (open_file(argv[1], &tetr) == 1)
			fillit(tetr);
		else
			ft_error("ERROR");
	}
	else
		ft_error("USAGE");
	return (0);
}
