/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 21:08:01 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/31 21:51:13 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		error(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			++j;
		}
		++i;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	display(int nb, char *str, unsigned int str_length)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= str_length)
		display(nbr / str_length, str, str_length);
	ft_putchar(str[nbr % str_length]);
}

void	ft_putnbr_base(int nb, char *str)
{
	unsigned int	str_length;

	str_length = 2;
	str_length = error(str);
	if (!str_length)
		return ;
	display(nb, str, str_length);
}
