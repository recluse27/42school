/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:43:30 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/02 20:50:42 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int		get_char_idx(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		parse_int(char *nbr, char *base_from)
{
	int sign;
	int i;
	int num;
	int char_idx;
	int	radix;

	i = 0;
	num = 0;
	sign = 1;
	radix = 0;
	while (base_from[radix] != '\0')
		radix++;
	if (nbr[0] == '-' || nbr[0] == '+')
		sign = 1 - 2 * (nbr[i++] == '-');
	while (nbr[i] != '\0')
	{
		char_idx = get_char_idx(nbr[i++], base_from);
		if (num > INT_MAX / radix
			|| (num == INT_MAX / radix && char_idx > INT_MAX % radix))
			return (sign == 1 ? INT_MAX : INT_MIN);
		if (char_idx == -1)
			return (0);
		num = radix * num + char_idx;
	}
	return (num * sign);
}

char	*convert_output_helper(char *digits, int len, int is_neg)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (len + 1));
	i = is_neg;
	while (i < len)
	{
		dest[i] = digits[len - 1 - i];
		i++;
	}
	if (is_neg)
		dest[0] = '-';
	dest[len] = '\0';
	return (dest);
}

char	*ft_convert_to_base(int nbr, char *base)
{
	int				radix;
	int				i;
	unsigned int	abs_n;
	char			digits[35];
	int				is_neg;

	radix = 0;
	while (base[radix] != '\0')
		radix++;
	if (nbr == 0)
		return ("0");
	is_neg = nbr < 0;
	abs_n = nbr < 0 ? -((unsigned int)(nbr)) : (unsigned int)(nbr);
	i = 0;
	while (abs_n >= 1)
	{
		digits[i++] = base[abs_n % radix];
		abs_n = abs_n / radix;
	}
	return (convert_output_helper(digits, i + is_neg, is_neg));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return (ft_convert_to_base(parse_int(nbr, base_from), base_to));
}
