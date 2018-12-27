/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:57:47 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/26 19:55:55 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int f;
	int s;

	f = -1;
	while (++f <= 98)
	{
		s = f;
		while (++s <= 99)
		{
			ft_putchar((char)((f / 10) + '0'));
			ft_putchar((char)((f % 10) + '0'));
			ft_putchar(' ');
			ft_putchar((char)((s / 10) + '0'));
			ft_putchar((char)((s % 10) + '0'));
			if (f != 98 || s != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
	ft_putchar('\n');
}
