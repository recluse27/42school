/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:27:23 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 11:31:58 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		includes(char *str, char letter)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == letter)
			return (1);
	}
	return (0);
}

int		get_word_count(char *str, char *breaks)
{
	int i;
	int wc;

	i = 0;
	wc = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i + 1] != '\0')
	{
		if (i == 0 && !includes(breaks, str[i]))
			wc++;
		else if (includes(breaks, str[i]) && !includes(breaks, str[i + 1]))
			wc++;
		i++;
	}
	return (wc);
}

int		get_word_len(char *str_ptr, char *breaks)
{
	int i;

	i = 0;
	while (*str_ptr && includes(breaks, *str_ptr))
		str_ptr++;
	while (str_ptr[i] && !includes(breaks, str_ptr[i]))
		i++;
	return (i);
}

char	**ft_split(char *str, char *breaks)
{
	int		i;
	int		k;
	int		word_count;
	char	**dest;

	word_count = get_word_count(str, breaks);
	dest = (char**)malloc(sizeof(char*) * (word_count + 1));
	k = 0;
	while (k < word_count)
	{
		dest[k] = (char*)malloc((get_word_len(str, breaks) + 1) * sizeof(char));
		while (*str && includes(breaks, *str))
			str++;
		i = 0;
		while (*str && !includes(breaks, *str))
			dest[k][i++] = *str++;
		dest[k++][i] = '\0';
	}
	dest[k] = 0;
	return (dest);
}

char	**ft_split_whitespaces(char *str)
{
	return (ft_split(str, " \t\n"));
}
