/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:23:33 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 16:23:36 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putline_helper(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
		ft_putchar(str[idx++]);
	ft_putchar('\n');
}

char	*trim_string(char *str)
{
	int i;

	while (*str == ' ')
		str++;
	i = 0;
	while (str[i] != '\0')
		i++;
	i -= 1;
	while (str[i] == ' ')
		i--;
	str[i + 1] = '\0';
	return (str);
}

int		ft_strcmp_helper(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*s1 == ' ')
		s1++;
	while (*s2 == ' ')
		s2++;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*arg;

	i = 0;
	while (i < argc)
	{
		arg = trim_string(argv[i]);
		if (ft_strcmp_helper(arg, "president") == 0
			|| ft_strcmp_helper(arg, "attack") == 0
			|| ft_strcmp_helper(arg, "Bauer") == 0)
			ft_putline_helper("Alert!!!");
		i++;
	}
	return (0);
}
