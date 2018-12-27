/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:27:46 by ale-goff          #+#    #+#             */
/*   Updated: 2018/08/05 21:42:36 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len(char *str)
{
	int l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

int		is_range(char c)
{
	if ((c < 58 && c > 48) || c == 46)
		return (1);
	return (0);
}

int		validation(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc != 10)
		return (0);
	while (i < argc)
	{
		j = 0;
		if (len(argv[i]) != 9)
			return (0);
		while (j < argc - 1)
		{
			if (is_range(argv[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
