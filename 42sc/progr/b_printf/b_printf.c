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

int		b_printf(const char *format, ...)
{
	va_list		arg;
	//	long	i;
	const char	*ch;
	char		*s;

	va_start(arg, format);
	ch = format;
	while (*ch != '\0')
	{
		if (*ch != '%')
		{
			ft_putchar(*ch);
		}
		else
		{
			ch++;
			if (*ch == 'c')
			{
				// i = va_arg(arg, int);
				ft_putchar(va_arg(arg, int));
			}
			else if (*ch == 'd' || *ch == 'i')
			{

				ft_putstr(ft_itoa_base(va_arg(arg, int), 10));
			}
			else if (*ch == 'o')
			{
				// i = va_arg(arg, unsigned int);
				ft_putstr(ft_itoa_base(va_arg(arg, unsigned int), 8));
			}
			else if (*ch == 's')
			{
				// s = va_arg(arg, char *);
				ft_putstr(va_arg(arg, char *));
			}
			else if (*ch == 'x')
			{
				// i = va_arg(arg, unsigned int);
				ft_putstr(ft_itoa_base(va_arg(arg, unsigned int), 16));
			}
			else if (*ch == 'p')
			{
				s = va_arg(arg, void *);
				ft_putstr(ft_itoa_base((unsigned long int)s, 16));
			}
			else if (*ch == 'u')
			{
				//i = va_arg(arg, unsigned long);
				//printf("%d\n", i);
				ft_putstr(ft_itoa_base(va_arg(arg, unsigned long), 10));
			}
			else if (*ch == '%')
			{
				ft_putchar('%');
			}
		}
		ch++;
	}
	va_end(arg);
	return (0);
}

int		main(void)
{
	int c = 3;
	int b = -3;
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

	b_printf("Hello %u terter\n", 1);
	printf("Hello %u terter\n", 1);
	b_printf("Hello %u terter\n", -1);
	printf("Hello %u terter\n", -1);

	b_printf("Hello %p terter\n", &c);
	printf("Hello %p terter\n", &c);
	b_printf("Hello %p terter\n", &b);
	printf("Hello %p terter\n", &b);

	b_printf("Hello %x terter\n", 13);
	printf("Hello %x terter\n", 13);
	b_printf("Hello %x terter\n", -3);
	printf("Hello %x terter\n", -3);

	b_printf("Hello %% terter\n", 4);
	// printf("Hello %% terter\n");		

	return (0);
}
