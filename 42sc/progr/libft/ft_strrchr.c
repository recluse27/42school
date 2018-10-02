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

char	*ft_strrchr(const char *str, int c)
{
	int		n;

	n = ft_strlen(str);
	while (n >= 0)
	{
		if (str[n] == c)
			return ((char*)&str[n]);
		n--;
	}
	return (NULL);
}
