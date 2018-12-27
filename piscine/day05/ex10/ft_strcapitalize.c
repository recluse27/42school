/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 21:40:23 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/31 22:19:18 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_islow(char c)
{
	return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

char	ft_isup(char c)
{
	return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

int		ft_alphanum(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && ft_alphanum(str[i + j]))
		{
			str[i + j] = j == 0 ? ft_isup(str[i + j]) : ft_islow(str[i + j]);
			j++;
		}
		i += j == 0 ? 1 : j;
	}
	return (str);
}
