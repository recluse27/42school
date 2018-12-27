/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 23:30:38 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/09 23:30:44 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		main(int ac, char **av)
{
	t_opts	opts;
	long	r;
	char	buff[BUFFS];

	if ((r = ft_tail_opts(&opts, ac, av)) != 0)
		return ((int)r);
	if (!opts.files)
		while ((r = read(0, buff, BUFFS)) != 0 && r != -1)
			;
	return (ft_tail(&opts));
}
