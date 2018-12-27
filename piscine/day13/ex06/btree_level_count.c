/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:50:43 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/10 15:52:57 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	max(int a, int b)
{
	return (a > b ? a : b);
}

int	btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (!root)
		return (0);
	if (root->left)
		count = max(count, btree_level_count(root->left));
	if (root->right)
		count = max(count, btree_level_count(root->right));
	return (count + 1);
}
