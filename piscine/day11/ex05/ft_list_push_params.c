/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:32:13 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/08 23:32:15 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

t_list  *ft_list_push_params(int ac, char **av)
{
	t_list	*curr;
	t_list	*prev;
	int		i;

	i = -1;
	prev = NULL;
	curr = NULL;
	while (++i < ac)
	{
		curr = ft_create_elem(av[i]);
		curr->next = prev;
		prev = curr;
	}
	return (curr);
}