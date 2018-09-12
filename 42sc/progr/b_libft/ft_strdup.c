/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:45 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/11 09:47:31 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s2;
	int k;
	k = 0;
	// unsigned int	len;

	// len = ft_strlen(s1);
	s2 = (char *)malloc(ft_strlen(s1) * sizeof(*s1) + 1);
	if (s2 == NULL)
		return ((char *)NULL);
	while (s1[k])
	{
		s2[k] = s1[k];
		k++;
	}
	s2[k] = '\0';
	return (s2);
}
