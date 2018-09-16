/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:20:58 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/16 12:31:55 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *c)
{
	while (*c != '\0')
		ft_putchar(*c++);
}

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

int		b_printf(char *format, ...)
{
	va_list	arg;
	int		i;
	char	*ch;
	char	*s;

	va_start(arg, format);
	ch = format;
	while (*ch != '\0')
	{
		while (*ch != '%' && *ch != '\0')
		{
			ft_putchar(*ch);
			ch++;
		}
		ch++;
		if (*ch == 'c')
		{
			i = va_arg(arg, int);
			ft_putchar(i);
		}
		else if (*ch == 'd' || *ch == 'i')
		{
			//i = va_arg(arg, int);
			// if (i < 0)
			// {
			// 	i *= -1; // i = -i;
			// 	ft_putchar('-');
			// }
			ft_putstr(ft_itoa_base(va_arg(arg, int), 10));
		}
		else if (*ch == 'o')
		{
			i = va_arg(arg, unsigned int);
			ft_putstr(ft_itoa_base(i, 8));
		}
		else if (*ch == 's')
		{
			s = va_arg(arg, char *);
			ft_putstr(s);
		}
		else if (*ch == 'x')
		{
			i = va_arg(arg, unsigned int);
			ft_putstr(ft_itoa_base(i, 16));
		}
		else if (*ch == 'p')
		{
			s = va_arg(arg, char *);
			ft_putstr(ft_itoa_base((unsigned long int)s, 16));
		}
		else if (*ch == 'u')
		{
			i = va_arg(arg, unsigned int);
			ft_putstr(ft_itoa_base(i, 10));
		}
		ch++;
	}
	va_end(arg);
	return (0);
}

int		main(void)
{
	b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);
	b_printf("Hello %d terter\n", -11);
	// printf("Hello %d terter\n", -11);

	b_printf("Hello %i terter\n", 10);
	// printf("Hello %i terter\n", 10);
	b_printf("Hello %i terter\n", -5);
	// printf("Hello %i terter\n", -5);

	//b_printf("Hello %s terter\n", "");
	//printf("Hello %s terter\n", "");
	//b_printf("Hello %s terter\n", "world");
	//printf("Hello %s terter\n", "world");

	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);
	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);

	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);
	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);

	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);
	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);

	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);
	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);

	return (0);
}
