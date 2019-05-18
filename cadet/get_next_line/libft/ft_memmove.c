/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:04:35 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/23 02:10:20 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sorc;

	dest = (unsigned char*)dst;
	sorc = (unsigned char *)src;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			dest[len] = sorc[len];
	}
	return (dest);
}
