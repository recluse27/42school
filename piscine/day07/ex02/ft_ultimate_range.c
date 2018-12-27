/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:37:19 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/02 20:55:17 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *dest;
	int i;
	int count;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	count = max - min;
	dest = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		dest[i] = min + i;
		i++;
	}
	*range = dest;
	return (count);
}
