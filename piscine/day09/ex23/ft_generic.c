/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:50:56 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 16:51:06 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

void	ft_generic(void)
{
	ft_putstr("Tut tut ; Tut tut");
}
