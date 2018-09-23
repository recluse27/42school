/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:20:58 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/22 15:19:28 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa(long long value, int base)
{
	char		*str;
	int			size;
	char		*tab;
	int			flag;
	long long	tmp;

	size = 1;
	tab = "0123456789abcdef";
	flag = (value < 0 && base == 10) ? 1 : 0;
	tmp = value;
	while (tmp /= base)
		size++;
	size += flag;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}

int		conv_set(const char c, va_list arg)
{
	if (c == 'd' || c == 'i')
		return (cnv_int(arg));
	else if (c == 'c')
		return (cnv_c(arg));
	else if (c == 's')
		return (cnv_s(arg));
	else if (c == 'p')
		return (cnv_p(arg));
	else if (c == 'o')
		return (cnv_o(arg));
	else if (c == 'u')
		return (cnv_u(arg));
	else if (c == 'x')
		return (cnv_x(arg));
	else if (c == '%')
		return (cnv_prc());
	return (0);
}

int		b_printf(const char *format, ...)
{
	va_list		arg;
	int			n;

	va_start(arg, format);
	n = 0;
	while (*format != '\0')
	{
		if (*format != '%' || (*format == '%' && *(format + 1) == '\0'))
		{
			ft_putchar(*format);
			n++;
		}
		else
		{
			format++;
			n += conv_set(*format, arg);
		}
		format++;
	}
	va_end(arg);
	return (n);
}
