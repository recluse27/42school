/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:38:23 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/08 23:14:22 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *current;

	current = head;
	while (current->next != NULL)
	{
		current = current->next;
    }
    current->next = malloc(sizeof(t_list));
    current->next->data = data;
    current->next->next = NULL;	
}