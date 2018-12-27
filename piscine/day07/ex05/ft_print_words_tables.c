/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:42:40 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/02 20:43:11 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr_helper(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx++]);
	}
}

int		ft_strcmp_helper(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	while (ft_strcmp_helper(tab[i], "") != 0)
	{
		ft_putstr_helper(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
