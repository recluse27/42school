/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:31:59 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/23 14:33:20 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		cnv_int(va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, int), 10);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		cnv_u(va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, unsigned long), 10);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		cnv_x(va_list arg)
{
	char	*str;
	str = ft_itoa(va_arg(arg, unsigned int), 16);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		cnv_o(va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, unsigned int), 8);
	ft_putstr(str);
	return (ft_strlen(str));
}
