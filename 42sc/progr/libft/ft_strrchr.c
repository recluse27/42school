/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:47:23 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/01 15:49:51 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[i]);
	while (i)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
