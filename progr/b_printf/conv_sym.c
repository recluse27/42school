/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_sym.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:33:31 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/24 15:40:48 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		cnv_s(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str);
	return (ft_strlen(str));
}

int		cnv_c(va_list arg)
{
	ft_putchar(va_arg(arg, int));
	return (1);
}

int		cnv_p(va_list arg)
{
	char	*str;

	ft_putstr("0x");
	str = ft_itoa((unsigned long)va_arg(arg, void *), 16);
	ft_putstr(str);
	return (ft_strlen(str) + 2);
}

int		cnv_prc(void)
{
	ft_putchar('%');
	return (1);
}
