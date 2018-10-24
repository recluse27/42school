/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:23:26 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/23 02:20:39 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_l_count(char const *str, char c)
{
	size_t		n;

	n = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != '\0')
			n++;
		while (*str && *str != c)
			str++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			words;
	char		**tab;

	i = 0;
	if (!s || !c)
		return ((void *)0);
	words = ft_l_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		tab[i] = (char *)malloc(sizeof(char) * (ft_l_count(s, c) + 1));
		j = 0;
		while (*s != c && *s)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
