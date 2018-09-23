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

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
		return (cnv_prc(arg));
	return (0);
}


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

int		cnv_int(va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, int), 10);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		cnv_p(va_list arg)
{
	char	*str;

	ft_putstr("0x");
	str = ft_itoa((unsigned long)va_arg(arg, void *), 16);
	ft_putstr(str);
	return (ft_strlen(str) + 2);
}

int		cnv_o(va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, unsigned int), 8);
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

int		cnv_prc(va_list arg)
{
	char	*str;

	ft_putchar('%');
	return (1);
}

int		b_printf(const char *format, ...)
{
	va_list		arg;
	const char	*ch;
	int			n;
	//char		*str;

	va_start(arg, format);
	ch = format;
	n = 0;
	while (*ch != '\0')
	{
		if (*ch != '%')
		{
			ft_putchar(*ch);
			n++;
		}
		else
		{
			ch++;
			n += conv_set(*ch, arg);
			// if (*ch == 'c')
			// {
			// 	ft_putchar(va_arg(arg, int));
			// 	n++;
			// }
			// else if (*ch == 'd' || *ch == 'i')
			// {
			// 	str = ft_itoa(va_arg(arg, int), 10);
			// 	ft_putstr(str);
			// 	n += ft_strlen(str);
			// }
			// else if (*ch == 'o')
			// {
			// 	str = ft_itoa(va_arg(arg, unsigned int), 8);
			// 	ft_putstr(str);
			// 	n += ft_strlen(str);
			// }
			// else if (*ch == 's')
			// {
			// 	str = va_arg(arg, char *);
			// 	if (!str)
			// 		str = "(null)";
			// 	ft_putstr(str);
			// 	n += ft_strlen(str);
			// }
			// else if (*ch == 'x')
			// {
			// 	str = ft_itoa(va_arg(arg, unsigned int), 16);
			// 	ft_putstr(str);
			// 	n += ft_strlen(str);
			// }
			// else if (*ch == 'p')
			// {
			// 	ft_putstr("0x");
			// 	str = ft_itoa((unsigned long)va_arg(arg, void *), 16);
			// 	ft_putstr(str);
			// 	n += ft_strlen(str) + 2;
			// }
			// else if (*ch == 'u')
			// {
			// 	str = ft_itoa(va_arg(arg, unsigned long), 10);
			// 	ft_putstr(str);
			// 	n += ft_strlen(str);
			// }
			// else if (*ch == '%')
			// {
			// 	ft_putchar('%');
			// 	n++;
			// }
		}
		ch++;
	}
	va_end(arg);
	return (n);
}

int		main(void)
{
	// int c = 3;
	// int b = -3;
	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);
	// b_printf("Hello %d terter\n", -11);
	// printf("Hello %d terter\n", -11);

	// b_printf("Hello %i terter\n", 10);
	// printf("Hello %i terter\n", 10);
	// b_printf("Hello %i terter\n", -5);
	// printf("Hello %i terter\n", -5);

	// b_printf("Hello %s terter\n", "");
	// printf("Hello %s terter\n", "");
	// b_printf("Hello %s terter\n", "world");
	// printf("Hello %s terter\n", "world");

	// b_printf("Hello %c terter\n", 'a');
	// printf("Hello %c terter\n", 'a');
	// b_printf("Hello %c terter\n", 33);
	// printf("Hello %c terter\n", 33);

	// b_printf("Hello %o terter\n", 1);
	// printf("Hello %o terter\n", 1);
	// b_printf("Hello %o terter\n", 100);
	// printf("Hello %o terter\n", 100);

	// b_printf("Hello %u terter\n", 1);
	// printf("Hello %u terter\n", 1);
	// b_printf("Hello %u terter\n", -1);
	// printf("Hello %u terter\n", -1);

	// b_printf("Hello %p terter\n", &c);
	// printf("Hello %p terter\n", &c);
	// b_printf("Hello %p terter\n", &b);
	// printf("Hello %p terter\n", &b);

	// b_printf("Hello %x terter\n", 13);
	// printf("Hello %x terter\n", 13);
	// b_printf("Hello %x terter\n", -3);
	// printf("Hello %x terter\n", -3);

	// b_printf("Hello % % terter\n");
	// printf("Hello % % terter\n");

	// printf("HALLO");
	// printf("%d", "%d");
	// printf("\n----\n");
	// printf("%d", "%d\n");
	// b_printf("%u", -356);
	// printf("\n - \n");
	// printf("%u", -356);
	// printf("\n ------------- \n");
	// b_printf("HALO %d", "%d", "%c");
	// printf("\n ---- \n");
	// printf("HALO %d", "%d", "%c");

	// printf("%d\n", b_printf("Hello %x terter", 120));
	// printf("%d\n", printf("Hello %x terter", 120));
	// printf("%d\n", b_printf("Hello %x terter", 12));
	// printf("%d\n", printf("Hello %x terter", 12));
	// printf("%d\n", b_printf("Hello %p terter", &b));
	// printf("%d\n", printf("Hello %p terter", &b));

	// printf("%d\n", b_printf("Hello %x terter", 74));
	// printf("%d\n", printf("Hello %x terter", 74));

	// b_printf("Hello %x terter\n", NULL);
	// printf("Hello %p terter\n", NULL);
	b_printf("%s%s%s\n", "test", "test", "test");
	// b_printf("%%%");

	return (0);
}
