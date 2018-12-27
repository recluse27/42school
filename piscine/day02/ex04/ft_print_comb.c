/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:23:02 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/26 19:31:57 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	char ar[3];

	while (ar[2] <= '9')
	{
		ar[1] = '0';
		while (ar[1] < ar[2])
		{
			ar[0] = '0';
			while (ar[0] < ar[1])
			{
				ft_putchar(ar[0]);
				ft_putchar(ar[1]);
				ft_putchar(ar[2]);
				if ((ar[0] < '7') && (ar[1] <= '8') && (ar[2] <= '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				ar[0]++;
			}
			ar[1]++;
		}
		ar[2]++;
	}
	ft_putchar('\n');
}
