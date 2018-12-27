/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 19:59:33 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/31 23:05:39 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	bytes;
	char			*sr;
	char			*dst;
	char			ch;

	bytes = 0;
	sr = src;
	dst = dest;
	while ((ch = *sr++))
	{
		if (bytes + 1 < size)
		{
			*dst++ = ch;
		}
		bytes++;
	}
	if (size != 0)
		*dst = '\0';
	return (bytes);
}
