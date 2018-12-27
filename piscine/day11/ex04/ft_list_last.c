/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:31:41 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/08 23:31:43 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data);

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *elem;

	elem = begin_list;
	while (elem && elem->next)
		elem = elem->next;

	return (elem);
}