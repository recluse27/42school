/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:29:49 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/13 15:29:57 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcon(char **arr, char *c)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strnew(1);
	while (arr[i])
	{
		tmp = ft_strjoin(str, arr[i]);
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, c);
		free(str);
		str = tmp;
		++i;
	}
	return (str);
}
