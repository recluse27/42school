/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:54:59 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/10 15:55:06 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_mapdup(char **map)
{
	int			i;
	char		**new;

	i = 0;
	while (map[i])
		i++;
	new = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (map[i])
	{
		new[i] = ft_strdup(map[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
