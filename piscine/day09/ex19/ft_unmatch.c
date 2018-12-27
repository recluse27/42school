/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:39:06 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 16:39:22 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int i;
	int count;
	int j;

	i = 0;
	while (i < length)
	{
		j = 0;
		count = 0;
		while (tab[j] < length)
		{
			if (tab[j] == tab[i])
				count++;
			j++;
		}
		if (count % 2)
			return (tab[i]);
		i++;
	}
	return (0);
}
