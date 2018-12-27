/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:36:30 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/02 20:36:45 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *dest;
	int i;
	int len;

	if (min >= max)
	{
		return (0);
	}
	len = max - min;
	dest = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}
