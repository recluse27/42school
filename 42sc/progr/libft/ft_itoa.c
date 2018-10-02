/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:28:07 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/01 17:28:28 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				sign;
	int				ten;
	char			*str;
	unsigned int	n2;

	ten = n < 0 ? 1 : 0;
	n2 = n;
	if ((sign = n) < 0)
		n2 = -n;
	while (n >= 9 || n <= -9)
	{
		ten++;
		n = n / 10;
	}
	if (!(str = (char *)malloc(sizeof(char) * (ten + 2))))
		return (NULL);
	str[ten + 1] = '\0';
	while (ten > -1)
	{
		str[ten--] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	str[0] = sign < 0 ? '-' : str[0];
	return (str);
}
