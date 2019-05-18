/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:35:34 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/08 15:37:41 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

char		*delete_slash(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (str[ft_strlen(str) - 1] != '/')
	{
		new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		while (i < ft_strlen(str) - 1)
		{
			new[i] = str[i];
			++i;
		}
		new[i] = '\0';
		return (new);
	}
	new = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (i < ft_strlen(str) - 1)
	{
		new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
