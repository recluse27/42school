/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:53:58 by amagnan           #+#    #+#             */
/*   Updated: 2018/11/18 19:14:21 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}
