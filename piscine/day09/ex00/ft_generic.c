/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:46:18 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 16:53:35 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_generic(void)
{
	char	*str;
	int		i;

	str = "Tut tut ; Tut tut";
	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}
