/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 12:00:02 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/28 21:46:21 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	else if ((nb % 2 == 0) || (nb % 3 == 0))
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if ((nb % i == 0) || (nb % (i + 2) == 0))
			return (0);
		i = i + 6;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
