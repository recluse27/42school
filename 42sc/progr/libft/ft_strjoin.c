/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:19:32 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/01 17:19:39 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*constr;

	constr = NULL;
	if (!s1 || !s2 ||
			!(constr = (ft_strnew(ft_strlen(s1) + ft_strlen(s2) - 1))))
		return (NULL);
	constr = ft_strcpy(constr, s1);
	constr = ft_strcat(constr, s2);
	return (constr);
}
