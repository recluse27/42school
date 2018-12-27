/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:27:51 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/10 16:00:06 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!root || !*root || !item)
	{
		if (item && root)
			*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, root->item) > 0)
	{
		if (root->right)
			btree_insert_data(root->right, item, cmpf);
		else
			root->right = btree_create_node(item);
	}
	else
	{
		if (root->left)
			btree_insert_data(root->left, item, cmpf);
		else
			root->left = btree_create_node(item);
	}
}
