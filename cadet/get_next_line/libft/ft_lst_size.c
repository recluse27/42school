/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:24:24 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/23 02:53:08 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_size(t_list *begin_list)
{
	t_list	*list;
	int		len;

	len = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}
