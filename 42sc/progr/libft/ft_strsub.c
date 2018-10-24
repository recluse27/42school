/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:18:02 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/01 17:18:52 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = ft_strnew(len);
	if (res && s)
	{
		i = 0;
		while (s[start] && i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
		if (res)
			return (res);
	}
	return (NULL);
}
