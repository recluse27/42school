/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:16:40 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 16:16:43 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	if (i >= j)
	{
		if (j >= k)
			return (k);
		return (i >= k ? k : i);
	}
	else
	{
		if (i >= k)
			return (i);
		return (j >= k ? k : j);
	}
}
