/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 19:04:22 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/31 22:01:33 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	bytes;
	char			*sr;
	char			*dst;
	char			ch;
	unsigned		orig_len;

	bytes = 0;
	sr = src;
	dst = dest;
	while (bytes < size && *dst)
	{
		dst++;
		bytes++;
	}
	orig_len = bytes + 1;
	while ((ch = *sr++))
	{
		if (bytes + 1 < size)
			*dst++ = ch;
		bytes++;
	}
	if (!(size == 0 || orig_len > size))
		*dst = '\0';
	return (bytes);
}
