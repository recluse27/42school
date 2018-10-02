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
	int		i;

	i = 0;
	if (NULL != (res = ft_strnew(len)) && s != NULL)
	{
		while (s[start] && len--)
			res[i++] = s[start++];
		if (res != NULL)
			return (res);
	}
	return (NULL);
}
