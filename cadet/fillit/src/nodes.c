/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:25:57 by vlazuka           #+#    #+#             */
/*   Updated: 2018/12/14 15:26:04 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

t_tetrimino		*make_node(char **ndata, char letter)
{
	t_tetrimino	*new;

	if (!(new = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	new->data = ndata;
	new->letter = letter;
	new->next = NULL;
	return (new);
}

int				add_node(t_tetrimino **head, t_tetrimino *new_node)
{
	t_tetrimino	*current;

	current = *head;
	if (!head || !*head || !new_node)
		return (-1);
	while (current->next)
		current = current->next;
	new_node->letter = current->letter + 1;
	current->next = new_node;
	return (1);
}

void			del_node(t_tetrimino **node)
{
	ft_mapdel((*node)->data);
	free(*node);
	*node = NULL;
}

void			erase_list(t_tetrimino **head)
{
	t_tetrimino	*link;

	if (*head == NULL)
		return ;
	link = *head;
	if (link->next)
		erase_list(&link->next);
	del_node(head);
}

int				ft_lst_size(t_tetrimino *tetr)
{
	int			i;
	t_tetrimino	*temp;

	i = 0;
	temp = tetr;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
