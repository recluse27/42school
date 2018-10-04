/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:23:00 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/01 17:23:02 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	st;
	size_t	end;

	st = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (s[st] != '\0' && ft_isspace(s[st]))
		st++;
	if (s[st] == '\0')
		return (ft_strdup(s + st));
	while (s[end - 1] && ft_isspace(s[end - 1]))
		end--;
	if (ft_strsub(s, st, end - st))
		return (ft_strsub(s, st, end - st));
	return (0);
}
