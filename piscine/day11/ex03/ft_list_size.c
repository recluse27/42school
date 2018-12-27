/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:31:11 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/08 23:31:13 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list  *ft_create_elem(void *data);

int     ft_list_size(t_list *begin_list)
{
	t_list *elem;
	int len;

	elem = begin_list;
	len = 0;
	while (elem)
	{
		elem = elem->next;
		len++;
	}
	return (len);
}