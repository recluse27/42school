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
	unsigned int		start;
	int					end;

	start = 0;
	if (s == NULL)
		return (NULL);
	end = (int)ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& s[start])
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			&& end > (int)start)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
