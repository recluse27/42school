/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:46:19 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/23 02:45:36 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	var;

	if (!(*needle))
		return ((char *)haystack);
	var = ft_strlen(needle);
	while (*haystack && var <= len--)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, var) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return ((void *)0);
}
