/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:32:03 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/01 16:33:57 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *var;

	var = (void *)malloc(sizeof(*var) * size);
	if (var)
	{
		ft_bzero(var, size);
		return (var);
	}
	return (NULL);
}
