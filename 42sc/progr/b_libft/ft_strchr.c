/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:44:44 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/10 22:40:43 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incluse <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (char *)s;
		s++;
	}
	return (char *)NULL;
}
