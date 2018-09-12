/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:38:40 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/11 09:30:30 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	p = b;
	i = 0;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}
