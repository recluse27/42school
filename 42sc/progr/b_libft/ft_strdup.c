/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:45 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/10 22:39:03 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*s2;
	unsigned int	len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(len * sizeof(*s1) + 1);
	if (s2 == NULL)
		return ((char *)NULL);
	while (*s1)
	{
		*s2 = *s1;
		s2++;
		s1++;
	}
	*s2 = '\0';
	return (s2);
}
