/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:32:56 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 16:34:37 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int index;
	int size;

	index = 0;
	size = length;
	while (index < length)
		if (!tab[index])
			size--;
	return (size);
}
