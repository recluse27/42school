/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:40:58 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/02 20:41:12 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	char	*args;
	int		i;
	int		j;
	int		o;

	args = malloc((argc) * sizeof(char));
	i = 1;
	o = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			args[o] = argv[i][j];
			o++;
			j++;
		}
		if ((i + 1) < argc)
			args[o] = '\n';
		o++;
		i++;
	}
	args[o - 1] = '\0';
	return (args);
}
