/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 23:28:49 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/09 23:28:55 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	ft_strlen(const char *str)
{
	char	*end;

	end = (char *)str;
	while (*end)
		++end;
	return ((unsigned)(end - str));
}
