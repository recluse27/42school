/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:23:10 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/23 01:23:25 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		l;
	char	t;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	i = 0;
	l--;
	while (i < l)
	{
		t = str[i];
		str[i] = str[l];
		str[l] = t;
		l--;
		i++;
	}
	return (str);
}
